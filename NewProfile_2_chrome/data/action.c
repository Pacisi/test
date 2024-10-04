Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("A-IM", 
		"x-bm,gzip");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_url("seed", 
		"URL=https://clientservices.googleapis.com/chrome-variations/seed?osname=win&channel=stable&milestone=116", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"116\", \"Not)A;Brand\";v=\"24\", \"Google Chrome\";v=\"116\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

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

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

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

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(8);

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
		"Name=USER", "Value=testuser_02", ENDITEM, 
		"Name=PASSWORD", "Value=testuser_02", ENDITEM, 
		"Name=FIRSTNAME", "Value=testuser_02", ENDITEM, 
		"Name=LASTNAME", "Value=testuser_02", ENDITEM, 
		"Name=STREET", "Value=testuser_02", ENDITEM, 
		"Name=CITY", "Value=testuser_02", ENDITEM, 
		"Name=COUNTRY", "Value=testuser_02", ENDITEM, 
		"Name=ACTION", "Value=Login", ENDITEM, 
		LAST);

	web_submit_data("logout.pl", 
		"Action=http://127.0.0.1:8800/cgi-bin/logout.pl", 
		"Method=GET", 
		"EncType=", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8800/cgi-bin/newProfile.pl?USER=testuser_02&PASSWORD=testuser_02&FIRSTNAME=testuser_02&LASTNAME=testuser_02&STREET=testuser_02&CITY=testuser_02&COUNTRY=testuser_02&ACTION=Login", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=SESSIONID", "Value=ECF30576F2369848AAB470A1E176E16288DDD81E1A342A3743B27462C98FBED4A2FB", ENDITEM, 
		LAST);

	return 0;
}