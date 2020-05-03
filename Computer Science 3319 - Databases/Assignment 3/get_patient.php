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
<title>Patient</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Here is the Patient Information:</h1>
<ol>

<?php
   $patient = $_POST["patient"];
   $query = 'SELECT patient.fname, patient.lname, doctor.fname AS "f", doctor.lname AS "l"  FROM doctor, patient WHERE ohip = '.$patient.'  AND licenumb IN (SELECT doclicenumb FROM patientdoctor WHERE patientohip = '.$patient.')';
   $result = mysqli_query($connection, $query);
   if (!result) 
   {
        die("Error - the search failed." . mysqli_error($connection));
   }
   while ($row = mysqli_fetch_assoc($result)) 
   {
		echo '<br>The Patient is '.$row["fname"].' ';
		echo ' '.$row["lname"].' <br>';
		echo "</br>";			
		echo 'Their Doctor is: '.$row["f"].' ';
		echo ' '.$row["l"].' <br>';
		echo "</br>";			
   }  
   mysqli_close($connection);
?>

</ol>
</body>
</html>
