<?php
function getYQLResult($restEndPoint, $args){
    $ch = curl_init($restEndPoint);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
    curl_setopt($ch, CURLOPT_TIMEOUT, 60);
    curl_setopt($ch, CURLOPT_HEADER, false);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array('Accept: application/json', 'Content-Type: application/x-www-form-urlencoded'));
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_POSTFIELDS, http_build_query($args));
    try {
        $retVal = curl_exec($ch);
        $code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        curl_close($ch);
        if($code !== 200){
            return false;
        }
        else {
            return json_decode($retVal, true);
 
        }
    }
    catch(Exception $e){
        return false;
    }
}

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
