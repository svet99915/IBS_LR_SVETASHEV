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
	
	
	

	lr_think_time(5);

	lr_start_transaction("Login");

	
	
	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	web_reg_find("Text/IC=User password was correct",
		LAST);
	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=66", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		LAST);
lr_end_transaction("Login",LR_AUTO);
	lr_think_time(5);

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

/*Correlation comment - Do not change!  Original value='010;559;09/01/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
web_reg_find("Text/IC=<B>{depart}</B> to <B>{arrive}</B>",LAST);
	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
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
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
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
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=45", ENDITEM,
		"Name=reserveFlights.y", "Value=13", ENDITEM,
		LAST);
lr_end_transaction("Search_Ticket",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Buy_Ticket");

	web_reg_find("Text/IC=Thank you for booking through Web Tours",
		LAST);
	
web_reg_find("Text/IC={creditCard}",LAST);
	web_submit_form("reservations.pl_3", 
		"Snapshot=t9.inf", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=pass1", "Value={pass1}", ENDITEM, 
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value={expDate}", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=62", ENDITEM, 
		"Name=buyFlights.y", "Value=5", ENDITEM, 
		LAST);
	
	
lr_end_transaction("Buy_Ticket",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Logout");
web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Logout",LR_AUTO);
lr_end_transaction("megatransaction",LR_AUTO);
	return 0;
}