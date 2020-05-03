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

<h1>New Doctor's Information:</h1>
<ol>

<?php
   $licenumb = $_POST["licenumb"];
   $fname = $_POST["fname"];
   $lname = $_POST["lname"];
   $specialty = $_POST["specialty"];
   $licedate = $_POST["licedate"];
   $worksathospcode = $_POST["worksathospcode"];
   $query = 'INSERT INTO doctor VALUES("'.$licenumb.'", "'.$fname.'", "'.$lname.'", "'.$specialty.'", "'.$licedate.'", "'.$worksathospcode.'")';
   if (!mysqli_query($connection, $query)) 
   {
        die("Error - the insertion failed." . mysqli_error($connection));
   }
   echo "You have successfully added your doctor.";
   mysqli_close($connection);
?>

</ol>
</body>
</html>

