<?php
$dbhost = "localhost";
$dbuser = "root";
$dbpass = "cs3319";
$dbname = "pradojciassign2db";
$connection = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
if (mysqli_connect_errno()) 
{
	die("Error - there was a problem connecting to the database:" .
	mysqli_connect_error() . " (" . mysqli_connect_errno() . ")" );
} 
?>
