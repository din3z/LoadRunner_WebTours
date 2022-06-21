Action()
{

	lr_start_transaction("UC02_DeleteTicket");
	
	/*Correlation comment - Do not change!  Original value='134086.749372215ziQHAiHpVHAiDDDDtVDicpfcDAcf' Name ='userSession' Type ='ResponseBased'*/
	correlate_userSession();
	
	open_site();

	lr_think_time(37);

	login();

	lr_think_time(18);

	lr_start_transaction("goto_itinerary");
		
	web_reg_find("Text/IC=<B>{FullName}",LAST);
	
	web_reg_save_param_regexp(
		"ParamName=f",
		"RegExp=name\=\"flightID\" value\=\(.*?)\/>",
		
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_end_transaction("goto_itinerary",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("delete_ticket");
	
	web_reg_find("Text=Error","Fail=Found",LAST);

	web_submit_form("itinerary.pl", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=40", ENDITEM, 
		"Name=removeFlights.y", "Value=13", ENDITEM, 
		LAST);
	
	lr_end_transaction("delete_ticket",LR_AUTO);

	lr_think_time(12);
	
	lr_start_transaction("goto_itinerary");
		
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_find("Text/IC={f}","Fail=Found", LAST);
	
	
	lr_end_transaction("goto_itinerary",LR_AUTO);

	log_out();

	lr_end_transaction("UC02_DeleteTicket",LR_AUTO);

	return 0;
}