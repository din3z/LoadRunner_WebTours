correlate_userSession(){
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value", 
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	return 0;
}

open_site(){
	lr_start_transaction("open_site");
	
	web_reg_find("Text=Welcome to the Web Tours site.",LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("open_site",LR_AUTO);
	return 0;
}

login(){
	lr_start_transaction("login");
	
	web_reg_find("Text=User password was correct",LAST);
	
	web_reg_find("Text/IC=Welcome, <b>{login}</b>",LAST);
	

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t35.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=31", ENDITEM,
		"Name=login.y", "Value=17", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	return 0;
}

click_flights() {
	lr_start_transaction("click_flights");

	web_reg_find("Text=<b>Find Flight</font></b>", LAST);

	web_url("Search Flights Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t36.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("click_flights", LR_AUTO);
	return 0;
	
}

goto_flights() {
	lr_start_transaction("goto_flights");

	web_reg_find("Text/IC=Flight departing from <B>{depart}</B>", LAST);


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



	lr_end_transaction("goto_flights", LR_AUTO);
	return 0;
}

find_flights() {
	lr_start_transaction("find_flights");

	web_reg_find("Text=Payment Details", LAST);

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

	lr_end_transaction("find_flights", LR_AUTO);
	return 0;
}

goto_itinerary() {
	lr_start_transaction("goto_itinerary");
	web_reg_find("Text=Since user has already logged on",
		LAST);

	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("goto_itinerary", LR_AUTO);
	return 0;
}

log_out(){
	lr_start_transaction("log_out");
	web_reg_find("Text=Welcome to the Web Tours site.",LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("log_out",LR_AUTO);

	return 0;
}
