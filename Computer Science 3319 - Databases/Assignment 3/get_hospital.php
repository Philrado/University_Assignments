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
<title>Hospital</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Hospital List:</h1>
<ol>

<?php
	$query = 'SELECT * FROM hospital JOIN doctor ON headdoclicenumb = licenumb ORDER BY hospname';
	$result = mysqli_query($connection, $query);
    if (!$result) 
	{
         die("Error - the 2nd database query has failed.");
    }
    while ($row = mysqli_fetch_assoc($result)) 
	{
        echo '<li>';
        echo 'The Head Doctor began employment on: '.$row["headdocstartdate"].' <br>';
        echo 'The Head doctor is: '.$row["fname"].'  '.$row["lname"].' <br>';
        echo 'The Hospital Name is: '.$row["hospname"].' <br> ';
		echo "</br>";	
    }
    mysqli_free_result($result);
?>

</ol>

<?php
   mysqli_close($connection);
?>

</body>
</html>



