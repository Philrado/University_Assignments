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
<title>Delete Doctor</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Your Doctors:</h1>
<form action = "delete.php" method = "post">
<h2>Select the Doctor You Would Like To Delete.</h2>
<ol>

<?php
	$query = 'SELECT * FROM doctor';
	$result = mysqli_query($connection, $query);
	if (!result) 
	{
		 die("Error - the 2nd database query has failed.");
	}
    while ($row = mysqli_fetch_assoc($result)) 
	{
        echo '<li>';
        echo '<input type = "radio" name = "doctor" value = "';
        echo $row["licenumb"];
        echo '">' . $row["fname"] . " " . $row["lname"] . "<br>";
		echo "</br>";		
    }
    mysqli_free_result($result);
?>

</ol>
<input type = "Confirm Submission" value = "Delete Selected Doctor">
</form>

<?php
   mysqli_close($connection);
?>

</body>
</html>




