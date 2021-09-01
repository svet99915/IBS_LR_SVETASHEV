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
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("Login");
	
web_reg_find("Text/IC=User password was correct",
		LAST);
	
	web_submit_form("login.pl", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=43", ENDITEM, 
		"Name=login.y", "Value=7", ENDITEM, 
		LAST);
lr_end_transaction("Login",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Delete_ticket");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t17.inf", 
		LAST);

	lr_think_time(5);

	web_reg_find("Text/IC=input type=\"hidden\"",
		LAST);
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=<OFF>", ENDITEM, 
		"Name=removeFlights.x", "Value=79", ENDITEM, 
		"Name=removeFlights.y", "Value=14", ENDITEM, 
		LAST);
lr_end_transaction("Delete_ticket",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Logout");
web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t19.inf", 
		LAST);
lr_end_transaction("Logout",LR_AUTO);

lr_end_transaction("megatransaction",LR_AUTO);
	return 0;
}