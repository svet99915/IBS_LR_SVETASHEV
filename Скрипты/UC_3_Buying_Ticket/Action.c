Action()
{

	lr_start_transaction("UC_1_3v2_Buying_Ticket_megatransaction");
	
	
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

	lr_start_transaction("Login");
	
	
	
	
	
	web_reg_find("Text/IC=User password was correct",
		LAST);
	
	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=57", ENDITEM,
		"Name=login.y", "Value=2", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Point_Of_Destination");
	
	web_reg_find("Text/IC=<B>{depart}</B> to <B>{arrive}</B>",LAST);
	web_reg_save_param("outboundFlight",
		"LB/IC=outboundFlight\" value=\"",
		"RB/IC=\"",
		"Ord=ALL",
		LAST);
	
	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=51", ENDITEM, 
		"Name=findFlights.y", "Value=3", ENDITEM, 
		LAST);
	
	lr_save_string(lr_paramarr_random("outboundFlight"), "outboundFlight_rnd");
	
	lr_end_transaction("Point_Of_Destination",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Choosing_a_ticket");

	

	
	
	web_reg_find("Text/IC=Flight Reservation",
		LAST);
	
	
	
	
	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight_rnd}", ENDITEM,  
		"Name=reserveFlights.x", "Value=37", ENDITEM, 
		"Name=reserveFlights.y", "Value=12", ENDITEM, 
		LAST);
	
	
	
	

	
	
	lr_end_transaction("Choosing_a_ticket",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Buy_Ticket");

	web_reg_find("Text/IC=Thank you for booking through Web Tours",
		LAST);
	
	
	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=pass1", "Value={pass}", ENDITEM, 
		"Name=pass2", "Value={pass}", ENDITEM,
		"Name=pass3", "Value={pass}", ENDITEM,
		"Name=pass4", "Value={pass}", ENDITEM,
		"Name=pass5", "Value={pass}", ENDITEM,
		"Name=pass6", "Value={pass}", ENDITEM,
		"Name=pass7", "Value={pass}", ENDITEM,
		"Name=pass8", "Value={pass}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value={expDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight_rnd}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=81", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("Buy_Ticket",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Delete_Ticket_Button");

	web_reg_save_param("flightID1",
		"LB=flightID\" value=\"",
		"RB=\"",
		LAST);
	
	

	
	
	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("Delete_Ticket_Button",LR_AUTO);
	
	
//	lr_start_transaction("Invoice");

//	web_submit_data("reservations.pl_4", 
//		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
//		"Method=POST", 
//		"TargetFrame=", 
//		"RecContentType=text/html", 
//		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
//		"Snapshot=t11.inf", 
//		"Mode=HTML", 
//		ITEMDATA, 
//		"Name=Book Another.x", "Value=48", ENDITEM, 
//		"Name=Book Another.y", "Value=6", ENDITEM, 
//		LAST);
//
//
//
//	lr_end_transaction("Invoice",LR_AUTO);
//	
	lr_think_time(5);

//	lr_start_transaction("Logout");
//	
//	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
//		LAST);
//	
//	web_url("welcome.pl", 
//		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
//		"TargetFrame=", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
//		"Snapshot=t9.inf", 
//		"Mode=HTML", 
//		LAST);
//	
//	lr_end_transaction("Logout",LR_AUTO);
//	
	lr_end_transaction("UC_1_3v2_Buying_Ticket_megatransaction",LR_AUTO);
	return 0;
}