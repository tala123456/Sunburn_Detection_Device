// this adds new mesured things onto the php quiry 

<?php
include "db_iconnect.php";
$check=0; 

//define for colums 
$device_ID = $_GET["id"]; 
$UV_mesured = $_GET["UVmes"]; 



// https://studenthome.hku.nl/~tanja.landolt/UV_Insertfile.php?id=3&UVmes=20  value 3 und 20 sind eingsetzte variablen die nicht als platzhalter fuer die arduino data eingesetz werden.

if(!filter_var($device_ID, FILTER_VALIDATE_INT)) {
    $check=1;
    }

    $query = "INSERT INTO ixd_data (id, user_id, UV_mesured, date_time) VALUES (NULL, $device_ID, $UV_mesured, current_timestamp())";


if ($check==0) { 
    echo show_result($mysqli, $query,"ixd_data");
    } else {
     echo "check failed, not valid";  
    }
?>

