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
<title>Doctor Information</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Information for the Specified Doctor:</h1>
<ol>

<?php
	$whichOwner = $_POST["doctor"];
	$query = 'SELECT * FROM doctor INNER JOIN hospital ON worksathospcode = hospcode AND licenumb = "' . $whichOwner . '"';
	$result = mysqli_query($connection, $query);
    if (!$result) 
	{
		 die("Error - the 2nd database query has failed.");
    }
    while ($row = mysqli_fetch_assoc($result)) 
	{
        echo 'Their License Number is: '.$row["licenumb"].' <br> ';
        echo 'Their First Name is: '.$row["fname"].' <br>';
        echo 'Their Last Name is: '.$row["lname"].' <br>';
        echo 'Their Specialty is: '.$row["specialty"].' <br>';
        echo 'Their License Start Date: '.$row["licedate"].' <br>';
        echo 'The Hospital they Work at: '. $row["hospname"].'<br> ';
    }
    mysqli_free_result($result);
?>

</ol>

<?php
   mysqli_close($connection);
?>

</body>
</html>







