Action()
{
	lr_start_transaction("UC01_BuyTicket");
	
	/*Correlation comment - Do not change!  Original value='134080.135439449ziQzHtzpQzzzzzzHtVDiAptiVi' Name ='userSession' Type ='ResponseBased'*/
	correlate_userSession();

	open_site();
	

	lr_think_time(13);

	login();
	
	lr_think_time(26);
	
	lr_start_transaction("click_flights");

	web_reg_find("Text=<b>Find Flight</font></b>",LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("click_flights",LR_AUTO);

	lr_start_transaction("goto_flights");

	web_reg_find("Text/IC=Flight departing from <B>{depart}</B>",LAST);
	
	
/*Correlation comment - Do not change!  Original value='571;57;06/15/2022' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
//		"Ordinal=ALL",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
		

		
	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t37.inf",
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
		"Name=findFlights.x", "Value=69", ENDITEM,
		"Name=findFlights.y", "Value=8", ENDITEM,
		LAST);
		
		

	lr_end_transaction("goto_flights",LR_AUTO);

	lr_think_time(22);

	lr_start_transaction("find_flights");
	
	web_reg_find("Text=Error","Fail=Found",LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t38.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatPref}", ENDITEM,
		"Name=seatPref", "Value={seatType}", ENDITEM,
		"Name=reserveFlights.x", "Value=61", ENDITEM,
		"Name=reserveFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("find_flights",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("payment_details");
	
	web_reg_find("Text=<B>Thank you for booking through Web Tours.</B>",LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t39.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={name}", ENDITEM,
		"Name=lastName", "Value={surname}", ENDITEM,
		"Name=address1", "Value={town}", ENDITEM,
		"Name=address2", "Value={street}", ENDITEM,
		"Name=pass1", "Value={fullName}", ENDITEM,
		"Name=creditCard", "Value={credit}", ENDITEM,
		"Name=expDate", "Value={exp}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=46", ENDITEM,
		"Name=buyFlights.y", "Value=6", ENDITEM,
		LAST);

	lr_end_transaction("payment_details",LR_AUTO);

	lr_think_time(14);

	log_out();
	
	lr_end_transaction("UC01_BuyTicket",LR_AUTO);
	
	return 0;
}