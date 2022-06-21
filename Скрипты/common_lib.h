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
