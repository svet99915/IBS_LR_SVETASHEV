Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(17);

	lr_start_transaction("Login");

	web_submit_form("login.pl", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=43", ENDITEM, 
		"Name=login.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(28);

	lr_start_transaction("Delete_ticket");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t17.inf", 
		LAST);

	lr_think_time(7);

	web_submit_form("itinerary.pl", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=<OFF>", ENDITEM, 
		"Name=removeFlights.x", "Value=79", ENDITEM, 
		"Name=removeFlights.y", "Value=14", ENDITEM, 
		LAST);

	lr_think_time(9);

	lr_start_transaction("Logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t19.inf", 
		LAST);

	return 0;
}