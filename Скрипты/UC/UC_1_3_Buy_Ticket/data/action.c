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

	lr_think_time(17);

	lr_start_transaction("Login");

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=66", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		LAST);

	lr_think_time(24);

	lr_start_transaction("Search_Ticket");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(5);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://127.0.0.1:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t4.inf", 
		LAST);

	web_custom_request("CalSelect.class", 
		"URL=http://127.0.0.1:1080/WebTours/classes/CalSelect.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t5.inf", 
		LAST);

	web_custom_request("Calendar.class", 
		"URL=http://127.0.0.1:1080/WebTours/classes/Calendar.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t6.inf", 
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=09/01/2021", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=09/02/2021", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=64", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_think_time(5);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=010;559;09/01/2021", ENDITEM, 
		"Name=reserveFlights.x", "Value=45", ENDITEM, 
		"Name=reserveFlights.y", "Value=13", ENDITEM, 
		LAST);

	lr_think_time(36);

	lr_start_transaction("Buy_Ticket");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t9.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=streeet", ENDITEM, 
		"Name=address2", "Value=cityyy", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=123435454", ENDITEM, 
		"Name=expDate", "Value=1212", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=62", ENDITEM, 
		"Name=buyFlights.y", "Value=5", ENDITEM, 
		LAST);

	lr_think_time(21);

	lr_start_transaction("Logout");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}