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
<title>Hospital Update</title>
</head>
<body>

<?php
   include 'connect_to_db.php';
?>

<h1>Hospital:</h1>
<ol>

<?php
   $current = $_POST["hospital"];
   $new = $_POST["hospname"];
   $query = 'UPDATE hospital SET hospname = "'.$new.'" WHERE hospcode = "'.$current.'" ';
   if (!mysqli_query($connection, $query)) 
   {
        die("Error - the update was unsuccessful." . mysqli_error($connection));
   }
   echo "The update was successful.";
   mysqli_close($connection);
?>

</ol>
</body>
</html>
