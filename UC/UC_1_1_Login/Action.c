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
 

	lr_start_transaction("Login");
    web_reg_find;
	web_url("webtours_3", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("header.html_2", 
		"URL=http://127.0.0.1:1080/webtours/header.html", 
		"Resource=0", 
		"Referer=http://127.0.0.1:1080/webtours/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/webtours/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);


	web_reg_find("Text/IC=User password was correct",
		LAST);

	
	web_submit_form("login.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=70", ENDITEM, 
		"Name=login.y", "Value=8", ENDITEM, 
		LAST);
lr_end_transaction("Login",LR_AUTO);


lr_start_transaction("Logout");


	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_url("welcome.pl_5", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
	
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);



	
lr_end_transaction("Logout",LR_AUTO);
	
	
lr_end_transaction("megatransaction",LR_AUTO);
	
	return 0;
}
