Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(11);

	lr_start_transaction("Sign_Up");

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t11.inf", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	lr_think_time(5);

	lr_start_transaction("Registration");

	web_submit_form("login.pl", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo13", ENDITEM, 
		"Name=password", "Value=bean13", ENDITEM, 
		"Name=passwordConfirm", "Value=bean13", ENDITEM, 
		"Name=firstName", "Value=Taco", ENDITEM, 
		"Name=lastName", "Value=Bell", ENDITEM, 
		"Name=address1", "Value=street", ENDITEM, 
		"Name=address2", "Value=cityyy", ENDITEM, 
		"Name=register.x", "Value=23", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t13.inf", 
		LAST);

	return 0;
}