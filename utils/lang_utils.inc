<?php

function getUserLanguage($supported_langs) {
   $lang = "en_US";
	$setcookie = true;

if (isset($_REQUEST['lang'])) {
        $locale = $_REQUEST['lang'];
	$setcookie = true;
} else if (isset($_COOKIE['tlang'])) {
   $locale = $_COOKIE['tlang'];
} else {
   $locale = Locale::acceptFromHttp($_SERVER['HTTP_ACCEPT_LANGUAGE']);
}
$lang = Locale::lookup($supported_langs,$locale,"en");
if (empty($lang)) $lang = "en_US";

	if ($setcookie){
	    setcookie("tlang",$lang,time()+3600);
	}
   return $lang;


}

function isLangRTL($lang){

	if ($lang == "ar") return true;
	if ($lang == "he") return true;

	return false;
}
?>
