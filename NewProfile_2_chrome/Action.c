Action()
{

lr_start_transaction("01_Startseite");

	web_reg_find("Text=Welcome to WakaTours",LAST);
	
	web_url("127.0.0.1:8800", 
		"URL=http://127.0.0.1:8800/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/general/fonts/Roboto-Condensed-regular/Roboto-Condensed-regular.woff2", "Referer=http://127.0.0.1:8800/general/fonts-Roboto-Condensed.css", ENDITEM, 
		"Url=/general/fonts/Roboto-Condensed-italic/Roboto-Condensed-italic.woff2", "Referer=http://127.0.0.1:8800/general/fonts-Roboto-Condensed.css", ENDITEM, 
		"Url=/general/fonts/Roboto-Condensed-700/Roboto-Condensed-700.woff2", "Referer=http://127.0.0.1:8800/general/fonts-Roboto-Condensed.css", ENDITEM, 
		LAST);
	
lr_end_transaction("01_Startseite",LR_AUTO);

lr_start_transaction("02_NewProfile");

	web_reg_find("Text=New Profile",LAST);
	
	web_submit_data("newProfile.pl", 
		"Action=http://127.0.0.1:8800/cgi-bin/newProfile.pl", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8800/", 
		"Snapshot=t57.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		EXTRARES, 
		"Url=https://content-autofill.googleapis.com/v1/pages/ChVDaHJvbWUvMTE2LjAuNTg0NS4xMTESOgl9548EtwIOFhIFDeqIV54SBQ1YnrzrEgUNUP5JSRIFDXK1lpUSBQ3Bes5fEgUN708BexIFDSGph-I=?alt=proto", "Referer=", ENDITEM, 
		LAST);
lr_end_transaction("02_NewProfile",LR_AUTO);

lr_start_transaction("03_Enter");

	web_reg_find("Text=Hello testuser{nr}",LAST);
	
/*Correlation comment - Do not change!  Original value='ECF30576F2369848AAB470A1E176E16288DDD81E1A342A3743B27462C98FBED4A2FB' Name ='SESSIONID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=SESSIONID",
		"TagName=input",
		"Extract=value",
		"Name=SESSIONID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_submit_data("newProfile.pl_2", 
		"Action=http://127.0.0.1:8800/cgi-bin/newProfile.pl", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8800/cgi-bin/newProfile.pl?", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=USER", "Value=testuser_{nr}", ENDITEM, 
		"Name=PASSWORD", "Value=testuser_{nr}", ENDITEM, 
		"Name=FIRSTNAME", "Value=testuser_{nr}", ENDITEM, 
		"Name=LASTNAME", "Value=testuser_{nr}", ENDITEM, 
		"Name=STREET", "Value=testuser_{nr}", ENDITEM, 
		"Name=CITY", "Value=testuser_{nr}", ENDITEM, 
		"Name=COUNTRY", "Value=testuser_{nr}", ENDITEM, 
		"Name=ACTION", "Value=Login", ENDITEM, 
		LAST);
lr_end_transaction("03_Enter",LR_AUTO);

lr_start_transaction("04_Logout");

	web_reg_find("Text=Welcome to WakaTours",LAST);	

	web_submit_data("logout.pl",
		"Action=http://127.0.0.1:8800/cgi-bin/logout.pl",
		"Method=GET",
		"EncType=",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:8800/cgi-bin/newProfile.pl?USER=testuser{nr}&PASSWORD=testuser{nr}&FIRSTNAME=testuser{nr}&LASTNAME=testuser{nr}&STREET=testuser{nr}&CITY=testuser{nr}&COUNTRY=testuser{nr}&ACTION=Login",
		"Snapshot=t59.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=SESSIONID", "Value={SESSIONID}", ENDITEM,
		LAST);
		
lr_end_transaction("04_Logout",LR_AUTO);

	return 0;
}