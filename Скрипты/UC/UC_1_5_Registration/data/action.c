Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(53);

	lr_start_transaction("Sign_Up");

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t7.inf", 
		LAST);

	lr_think_time(50);

	lr_start_transaction("Registration");

	web_submit_form("login.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo12", ENDITEM, 
		"Name=password", "Value=bean12", ENDITEM, 
		"Name=passwordConfirm", "Value=bean12", ENDITEM, 
		"Name=firstName", "Value=Coco", ENDITEM, 
		"Name=lastName", "Value=Jumbo", ENDITEM, 
		"Name=address1", "Value=streeeet", ENDITEM, 
		"Name=address2", "Value=cityyyy", ENDITEM, 
		"Name=register.x", "Value=44", ENDITEM, 
		"Name=register.y", "Value=12", ENDITEM, 
		LAST);

	lr_think_time(16);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t9.inf", 
		LAST);

	return 0;
}