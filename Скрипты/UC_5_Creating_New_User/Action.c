Action()
{

	
	lr_start_transaction("UC_1_5v2_Creating_New_User_megatransaction");
	
	
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

	lr_start_transaction("Creating_User");
web_reg_find("Text/IC=Please choose a username and password combination for your account",
	             LAST);
	
	web_url("sign up now", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Creating_User",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Signup");
web_reg_find("Text/IC=We hope we can meet all your current and future travel needs",
			LAST);
	
	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo{rnd}", ENDITEM, 
		"Name=password", "Value=bean{rnd}", ENDITEM, 
		"Name=passwordConfirm", "Value=bean{rnd}", ENDITEM, 
		"Name=firstName", "Value=jojo{rnd}", ENDITEM, 
		"Name=lastName", "Value=bean{rnd}", ENDITEM, 
		"Name=address1", "Value=street{rnd}", ENDITEM, 
		"Name=address2", "Value=city{rnd}", ENDITEM, 
		"Name=register.x", "Value=65", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);
//
//	web_url("button_next.gif", 
//		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
//		"TargetFrame=body", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
//		"Snapshot=t5.inf", 
//		"Mode=HTML", 
//		LAST);

	lr_end_transaction("Signup",LR_AUTO);
	lr_start_transaction("Logout");
	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Logout",LR_AUTO);
	
	lr_end_transaction("UC_1_5v2_Creating_New_User_megatransaction",LR_AUTO);

	return 0;
}