Action()
{

	lr_start_transaction("UC06_SearchFlights");
/*Correlation comment - Do not change!  Original value='134108.331956258ziQiVQHpDcftVDiQpViDQf' Name ='userSession' Type ='ResponseBased'*/
	correlate_userSession();

	open_site();

	lr_think_time(5);

	login();
	
	click_flights();
	goto_flights();

	find_flights();
	lr_think_time(5);


	lr_end_transaction("UC06_SearchFlights",LR_AUTO);


	return 0;
}