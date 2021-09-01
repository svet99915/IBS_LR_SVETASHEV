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
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=26", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);

	
	lr_end_transaction("Login",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Search_Ticket");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

     //динамическая проверка 
	web_reg_find("Text/IC=<B>{Depart}</B> to <B>{Arrive}</B>",LAST);

/*Correlation comment - Do not change!  Original value='020;491;09/01/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_form("reservations.pl",
		"Snapshot=t4.inf",
		ITEMDATA,
		"Name=depart", "Value={Depart}", ENDITEM,
		"Name=departDate", "Value={DepartDate}", ENDITEM,
		"Name=arrive", "Value={Arrive}", ENDITEM,
		"Name=returnDate", "Value={ReturnDate}", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=roundtrip", "Value=<OFF>", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=53", ENDITEM,
		"Name=findFlights.y", "Value=12", ENDITEM,
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");
//
//	web_reg_save_param("outboundFlight",
//		"LB=name=outboundFlight\" value=\"",
//		"RB="",
//		"Ord=ALL",
//		LAST);

	web_submit_form("reservations.pl_2",
		"Snapshot=t5.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=21", ENDITEM,
		"Name=reserveFlights.y", "Value=12", ENDITEM,
		LAST);
lr_end_transaction("Search_Ticket",LR_AUTO);
	lr_think_time(5);

	lr_start_transaction("Logout");
web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t6.inf", 
		LAST);
	lr_end_transaction("Logout",LR_AUTO);
	
lr_end_transaction("megatransaction",LR_AUTO);
	return 0;
}