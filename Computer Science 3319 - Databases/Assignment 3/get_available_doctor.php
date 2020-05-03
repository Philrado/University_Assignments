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
<title>Available Doctor - Has no Current Patients</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Available Doctors:</h1>
<ol>

<?php
   $query = 'SELECT * FROM doctor WHERE licenumb NOT IN (SELECT doclicenumb FROM patientdoctor GROUP BY doclicenumb HAVING COUNT(*) > 0)';
   $result = mysqli_query($connection, $query);
   if (!mysqli_query($connection, $query)) 
   {
        die("Error - the search failed." . mysqli_error($connection));
   }
   while ($row = mysqli_fetch_assoc($result)) 
   {
        echo '<li>';
        echo ''. $row["fname"] .'  '. $row["lname"] . '<br>';
   }
   mysqli_close($connection);
?>

</ol>
</body>
</html>




