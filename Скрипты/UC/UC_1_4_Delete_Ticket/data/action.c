Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(17);

	lr_start_transaction("Login");

	web_submit_form("login.pl", 
		"Snapshot=t9.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=22", ENDITEM, 
		"Name=login.y", "Value=1", ENDITEM, 
		LAST);

	lr_think_time(25);

	lr_start_transaction("Delete_Tickets");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t10.inf", 
		LAST);

	lr_think_time(4);

	web_submit_form("itinerary.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM, 
		"Name=removeAllFlights.x", "Value=59", ENDITEM, 
		"Name=removeAllFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(12);

	lr_start_transaction("Logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t12.inf", 
		LAST);

	return 0;
}