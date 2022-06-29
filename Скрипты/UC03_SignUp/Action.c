Action()
{

	lr_start_transaction("UC03_SignUp");
	
	open_site();
	
	lr_think_time(5);

	lr_start_transaction("click_signUp");
	
	web_reg_find("Text=Customer Profile",
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_signUp",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("customerProfile");
	
	web_reg_find("Fail=Found",
		"Text=Your username is taken. ",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={name}", ENDITEM, 
		"Name=password", "Value={name}", ENDITEM, 
		"Name=passwordConfirm", "Value={name}", ENDITEM, 
		"Name=firstName", "Value={name}", ENDITEM, 
		"Name=lastName", "Value={name}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={town}", ENDITEM, 
		"Name=register.x", "Value=60", ENDITEM, 
		"Name=register.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("customerProfile",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("continue");
	
	web_reg_find("Text/IC=Welcome, <b>{name}</b>,",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("continue",LR_AUTO);

	lr_think_time(5);
	
	if (atoi(lr_eval_string("{randForPage}"))==1){
		click_flights();
	}

	if (atoi(lr_eval_string("{randForExit}"))==1){
		log_out();
	}
	
	
	
	lr_end_transaction("UC03_SignUp",LR_AUTO);
	

	return 0;
}