Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(27);

	lr_start_transaction("Signup");

	web_url("sign up now", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(42);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo13", ENDITEM, 
		"Name=password", "Value=bean13", ENDITEM, 
		"Name=passwordConfirm", "Value=bean13", ENDITEM, 
		"Name=firstName", "Value=jojo13", ENDITEM, 
		"Name=lastName", "Value=bean13", ENDITEM, 
		"Name=address1", "Value=street13", ENDITEM, 
		"Name=address2", "Value=city13", ENDITEM, 
		"Name=register.x", "Value=60", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);

	lr_think_time(21);

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo15", ENDITEM, 
		"Name=password", "Value=bean15", ENDITEM, 
		"Name=passwordConfirm", "Value=bean15", ENDITEM, 
		"Name=firstName", "Value=jojo15", ENDITEM, 
		"Name=lastName", "Value=bean15", ENDITEM, 
		"Name=address1", "Value=street15", ENDITEM, 
		"Name=address2", "Value=city15", ENDITEM, 
		"Name=register.x", "Value=65", ENDITEM, 
		"Name=register.y", "Value=5", ENDITEM, 
		LAST);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Signup",LR_AUTO);

	return 0;
}