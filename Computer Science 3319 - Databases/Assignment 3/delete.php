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
<title>Delete</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Delete:</h1>
<ol>

<?php
   $deletedDoctor = $_POST["doctor"];
   $query = 'DELETE FROM doctor WHERE licenumb = "'.$deletedDoctor.'"';
   if (!mysqli_query($connection, $query)) 
   {
        die("Error - the insertion failed." . mysqli_error($connection));
   }
   echo "The Selected Doctor was Deleted Successfully.";
   mysqli_close($connection);
?>

</ol>
</body>
</html>



