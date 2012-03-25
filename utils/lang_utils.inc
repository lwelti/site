<?php
// FB User Array
function getUserLanguage($supported_langs, $fbUserArray = array()) {
   $lang = "en_US";
	$setcookie = true;

if ( isset($fbUserArray["verified"]) ) {
error_log("FB User locale:" . $fbUserArray["locale"]);
}


if (isset($_REQUEST['lang'])) {
        $locale = $_REQUEST['lang'];
	$setcookie = true;
} else if (isset($_COOKIE['tlang'])) {
   $locale = $_COOKIE['tlang'];
} else if ( isset($fbUserArray["verified"]) ) {
error_log("FB User locale:" . $fbUserArray["locale"]);
	$locale = $fbUserArray["locale"];
} else {
   $locale = locale_accept_from_http($_SERVER['HTTP_ACCEPT_LANGUAGE']);
}
$lang = locale_lookup($supported_langs,$locale,'en_US');
error_log("lookup = $lang");
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
