Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(24);

	lr_start_transaction("Login");

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=26", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);

	lr_think_time(28);

	lr_start_transaction("Search_Ticket");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=09/01/2021", ENDITEM, 
		"Name=arrive", "Value=London", ENDITEM, 
		"Name=returnDate", "Value=09/02/2021", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=findFlights.x", "Value=53", ENDITEM, 
		"Name=findFlights.y", "Value=12", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=020;491;09/01/2021", ENDITEM, 
		"Name=reserveFlights.x", "Value=21", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);

	lr_think_time(14);

	lr_start_transaction("Logout");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t6.inf", 
		LAST);

	return 0;
}