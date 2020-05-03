<!DOCTYPE html>
<html>
<head>
<style>

h1 { color:red;
   font-family: 'Segoe UI Semibold'; font-size: 36px;
}
h2 { color:red;
   font-family: 'Segoe UI Semibold'; font-size: 30px;
}
body { background-color:yellow;
	font-size:22px;
	font-family:"Times New Roman";
}

</style>
<meta charset = "utf-8">
<title>Doctor</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Your Doctors:</h1>
<form action = "get_info.php" method = "post">
<h2>Select the Doctor Whose File you Would Like to See.</h2>
<ol>

<?php
   $ordering = $_POST["order"];
   $query = 'SELECT * FROM doctor ORDER BY '.$ordering.'';
   $result = mysqli_query($connection,$query);
   if (!$result) 
   {
         die("Error - the 2nd database query has failed.");
   }
   while ($row = mysqli_fetch_assoc($result)) 
   {
		echo '<li>';
		echo '<input type = "radio" name = "doctor" value = "';
		echo $row["licenumb"];
		echo '">' . $row["fname"] . " " . $row["lname"] . "<br>";
   }
	mysqli_free_result($result); 
?>

</ol>
<input type = "Submission Confirmed" value = "Obtain Doctor's Information">
</form>

<?php
   mysqli_close($connection);
?>

</body>
</html>
