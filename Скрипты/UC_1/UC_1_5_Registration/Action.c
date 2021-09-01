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
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	lr_start_transaction("Sign_Up");

	web_reg_find("Text/IC=Please choose a username and password",
		LAST);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t11.inf", 
		LAST);
	
lr_end_transaction("Sign_Up",LR_AUTO);
	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_think_time(5);

	lr_start_transaction("Registration");
web_reg_find("Text/IC=<b>jojo{username_rnd}</b>",LAST);
	web_submit_form("login.pl", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo{username_rnd}", ENDITEM, 
		"Name=password", "Value=bean{password_rnd}", ENDITEM, 
		"Name=passwordConfirm", "Value=bean{password_rnd}", ENDITEM, 
		"Name=firstName", "Value=Taco", ENDITEM, 
		"Name=lastName", "Value=Bell", ENDITEM, 
		"Name=address1", "Value=street", ENDITEM, 
		"Name=address2", "Value=cityyy", ENDITEM, 
		"Name=register.x", "Value=23", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);

	lr_think_time(5);

	web_reg_find("Text/IC= Since user has already logged on",
		LAST);
	
	
	
	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t13.inf", 
		LAST);
	lr_end_transaction("Registration",LR_AUTO);
lr_end_transaction("megatransaction",LR_AUTO);

	return 0;
}