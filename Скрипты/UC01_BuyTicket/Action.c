Action()
{
	lr_start_transaction("UC01_BuyTicket");
	
	/*Correlation comment - Do not change!  Original value='134080.135439449ziQzHtzpQzzzzzzHtVDiAptiVi' Name ='userSession' Type ='ResponseBased'*/
	correlate_userSession();

	open_site();
	

	lr_think_time(5);

	login();
	
	lr_think_time(5);
	
	click_flights();
	goto_flights();
	lr_think_time(5);

	find_flights();

	lr_think_time(5);

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

	lr_think_time(5);

	log_out();
	
	lr_end_transaction("UC01_BuyTicket",LR_AUTO);
	
	return 0;
}