Action()
{
	lr_start_transaction("UC_1_1v2_Login_megatransaction");
	
	
	lr_start_transaction("Entry");
	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
			LAST);

	web_reg_save_param_regexp(
		"ParamName=userSession",
		"RegExp=name=\"userSession\"\\ value=\"(.*?)\"/>\\\n<table\\ border",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	
	
	
	
	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("Entry",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Login");

	web_reg_find("Text/IC=User password was correct",
			LAST);
	
	
	
	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=66", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);

	
	lr_end_transaction("Login",LR_AUTO);
	
	
	lr_think_time(5);

	lr_start_transaction("Logout");
	
	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
			LAST);
	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);
	
	

	lr_end_transaction("UC_1_1v2_Login_megatransaction",LR_AUTO);
	
	
	return 0;
}