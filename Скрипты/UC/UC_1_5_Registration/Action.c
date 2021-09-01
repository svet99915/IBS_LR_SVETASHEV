Action()
{
	lr_start_transaction("megatransaction");

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);
	
	

	lr_start_transaction("Sign_Up");
	
	//не знаю даже, что тут можно проверить
	
//web_reg_find("Text/IC=User password was correct",
//		LAST);
	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t7.inf", 
		LAST);
lr_end_transaction("Sign_Up",LR_AUTO);
	lr_think_time(5);
//на данный момент сделано местным рандомом (скоро что-нибудь придумаю)
	lr_start_transaction("Registration");

	web_submit_form("login.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=username", "Value={username_rnd}", ENDITEM, 
		"Name=password", "Value={password_rnd}", ENDITEM, 
		"Name=passwordConfirm", "Value=bean12", ENDITEM, 
		"Name=firstName", "Value=Coco", ENDITEM, 
		"Name=lastName", "Value=Jumbo", ENDITEM, 
		"Name=address1", "Value=streeeet", ENDITEM, 
		"Name=address2", "Value=cityyyy", ENDITEM, 
		"Name=register.x", "Value=44", ENDITEM, 
		"Name=register.y", "Value=12", ENDITEM, 
		LAST);

	lr_think_time(5);

//	web_image("button_next.gif", 
//		"Src=/WebTours/images/button_next.gif", 
//		"Snapshot=t9.inf", 
//		LAST);
lr_end_transaction("Registration",LR_AUTO);
lr_end_transaction("megatransaction",LR_AUTO);
	return 0;
}