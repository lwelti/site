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
function getYQLResultGET($restEndPoint, $args){
    $ch = curl_init($restEndPoint);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
    curl_setopt($ch, CURLOPT_TIMEOUT, 60);
    curl_setopt($ch, CURLOPT_HEADER, false);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array('Accept: application/json', 'Content-Type: application/x-www-form-urlencoded'));
    curl_setopt($ch, CURLOPT_POST, false);
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
?>
