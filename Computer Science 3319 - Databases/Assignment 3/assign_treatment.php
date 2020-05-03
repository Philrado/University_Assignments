<!DOCTYPE html>
<html>
<head>
<style>

h1 { color:red;
   font-family: 'Segoe UI Semibold'; font-size: 36px;
}
body { background-color:yellow;
	font-size:22px;
	font-family:"Times New Roman";
}

</style>
<meta charset = "utf-8">
<title>Assign Doctor</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Assign Doctor:</h1>
<ol>

<?php
   $doc = $_POST["doctor"];
   $pa = $_POST["patient"];
   $query = 'INSERT INTO patientdoctor VALUES("'.$doc.'", '.$pa.')';
   if (!mysqli_query($connection, $query)) 
   {
        die("Error - the attempt to assign has failed." . mysqli_error($connection));
   }
   echo "The doctor was successfully assigned to the specified patient.";
   mysqli_close($connection);
?>

</ol>
</body>
</html>
