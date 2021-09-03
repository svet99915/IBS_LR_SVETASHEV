Action()
{

	lr_start_transaction("UC_1_4v2_Delete_Ticket_megatransaction");
	
	
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
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=57", ENDITEM,
		"Name=login.y", "Value=2", ENDITEM,
		LAST);

	lr_end_transaction("Login",LR_AUTO);
	
	
	lr_think_time(5);

	lr_start_transaction("Delete_Ticket_Button");

	

	web_reg_find("Text/IC=User wants the intineraries",
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
	
	
	lr_think_time(5);
	
	lr_start_transaction("Delete_Ticket");
	
	
//	web_reg_save_param("Delete_param",
//		"LB=A total of ",
//		"RB= scheduled flights",
//		LAST);
	
	
//	web_reg_find("Text/IC=A total of {Delete_param_str} scheduled flights",
//		LAST);
	
	
	
	// этот текст пишется после удаления
		web_reg_find("Text/IC= scheduled flights",
		LAST);
	
	
	
	web_submit_form("itinerar" 
	                "y.pl",
		"Snapshot=t26.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
//		"Name=2", "Value=on", ENDITEM, 
//		"Name=3", "Value=on", ENDITEM, 
//		"Name=4", "Value=<OFF>", ENDITEM, 
//		"Name=5", "Value=<OFF>", ENDITEM, 
		"Name=removeFlights.x", "Value=59", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		LAST);
	
	lr_save_string("Delete_param", "Delete_param_str");
	
//	web_submit_data("itinerary.pl", 
//		"Action=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
//		"Method=POST", 
//		"TargetFrame=", 
//		"RecContentType=text/html", 
//		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
//		"Snapshot=t4.inf", 
//		"Mode=HTML", 
//		ITEMDATA, 
//		"Name=1", "Value=on", ENDITEM, 
////		"Name=flightID", "Value=82741539-7822-b", ENDITEM, 
////		"Name=flightID", "Value=210296680-1568-JB", ENDITEM, 
////		"Name=.cgifields", "Value=1", ENDITEM, 
////		"Name=.cgifields", "Value=2", ENDITEM, 
//		"Name=removeFlights.x", "Value=59", ENDITEM, 
//		"Name=removeFlights.y", "Value=7", ENDITEM, 
//		LAST);

	lr_end_transaction("Delete_Ticket",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("Logout");
	
	web_reg_find("Text/IC= A Session ID has been created and loaded into a cookie called MSO",
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("Logout",LR_AUTO);
	
	lr_end_transaction("UC_1_4v2_Delete_Ticket_megatransaction",LR_AUTO);
	
	return 0;
}