Action()
{
	lr_start_transaction("megatransaction");
	web_reg_save_param_regexp(
		"ParamName=userSession",
		"RegExp=name=\"userSession\"\\ value=\"(.*?)\"/>\\\n<table\\ border",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	
	web_reg_save_param_ex( 
	    "ParamName=userSession",
	    "LB/IC=userSession\" value=\"",
	    "RB/IC=\"/>",
	    "Ordinal=1",
	     LAST);

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("Login");
web_reg_find("Text/IC=User password was correct",
		LAST);
	web_submit_form("login.pl", 
		"Snapshot=t9.inf", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=22", ENDITEM, 
		"Name=login.y", "Value=1", ENDITEM, 
		LAST);
lr_end_transaction("Login",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Delete_Tickets");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t10.inf", 
		LAST);
lr_end_transaction("Delete_Tickets",LR_AUTO);
	lr_think_time(5);

	web_submit_form("itinerary.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM, 
		"Name=removeAllFlights.x", "Value=59", ENDITEM, 
		"Name=removeAllFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(5);

	lr_start_transaction("Logout");
web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t12.inf", 
		LAST);
lr_end_transaction("Logout",LR_AUTO);
lr_end_transaction("megatransaction",LR_AUTO);
	return 0;
}