Action()
{
	lr_start_transaction("UC05_Itinerary");

/*Correlation comment - Do not change!  Original value='134108.403807209ziQicAVpAcAiDDDDtVDiQpcAzVcf' Name ='userSession' Type ='ResponseBased'*/
	correlate_userSession();

	open_site();

	lr_think_time(20);

	login();

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

	lr_end_transaction("goto_itinerary",LR_AUTO);

	lr_think_time(9);

	log_out();
	
	lr_end_transaction("UC05_Itinerary",LR_AUTO);


	return 0;
}