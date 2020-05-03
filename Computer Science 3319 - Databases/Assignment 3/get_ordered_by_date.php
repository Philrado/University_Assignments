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
<title>Doctor</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>The List of Doctors Licensed Before The Specified Date:</h1>
<ol>

<?php
	$date = $_POST["date"];
	$query = 'SELECT * FROM doctor WHERE licedate < "'.$date.'"';
	$result = mysqli_query($connection, $query);
	if (!result) 
	{
		die("Error - the search failed." . mysqli_error($connection));
	}
	while ($row = mysqli_fetch_assoc($result)) 
	{
		echo '<li>';
		echo ''.$row["fname"].' '.$row["lname"].' <br>';
		echo 'The Doctor Specialty is : '.$row["specialty"].' <br>';
		echo 'Their License Date is : '.$row["licedate"].' <br>';    
		echo "</br>";		
	}
	mysqli_close($connection);
?>

</ol>
</body>
</html>
