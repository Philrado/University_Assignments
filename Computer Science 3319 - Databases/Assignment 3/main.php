<!DOCTYPE html>
<html>       
<head>
<style>

h1 { color:red;
   font-family: 'Segoe UI Semibold'; font-size: 36px;
}
h2 { color:blue;
   font-family: 'Segoe UI Semibold'; font-size: 26px;
}
h3 { color:black;
   font-family: 'Segoe UI Semibold'; font-size: 20px;
}
p#initial_message { float:right;
   font-family: 'Segoe UI Semibold'; font-size: 30px;
}
body { background-color:yellow;
	font-size:22px;
	font-family:"Times New Roman";
}

</style>
<meta charset = "utf-8">
</head>

<?php
   include 'connect_to_db.php';
?>

<h1>CS3319 Hospital Database</h1>

<h3>__________________________________________________________________________________________</h3>
<h2>1.) The Doctors:</h2>
<form action = "get_doctor.php" method = "post">
<?php
   include 'get_data.php';
?>
<p>
<input type = "Confirm Submission" value = "Get Doctors">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>2.) List of Doctors Licensed Before a Given Date:</h2>
<form action = "get_ordered_by_date.php" method = "post">
Enter Date: <input type = "date" name = "date"><br>
<p>
<input type = "Confirm Submission" value = "Get List">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>3.) Add a Doctor:</h2>
<form action = "add_doctor.php" method = "post" enctype = "multipart/form-data">
Doctor's License Number: <input type = "text" name = "licenumb"><br>
Doctor's First Name: <input type = "text" name = "fname"><br>
Doctor's Last Name: <input type = "text" name = "lname"><br>
Doctor's Specialty : <input type = "text" name = "specialty"><br>
Doctor's License Start Date: <input type = "date" name = "licedate"><br>
<p>
The Hospital the Doctor Work's at: <br>
<input type = "radio" name = "hospital" value = "BBC">St. Joseph, London<br>
<input type = "radio" name = "hospital" value = "ABC">Victoria, London<br>
<input type = "radio" name = "hospital" value = "DDE">Victoria, Victoria<br>
<p>
<input type = "Confirm Submission" value = "Add New Doctor">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>4.) Delete a Doctor:</h2>
<form action = "delete_doctor.php" method = "post">
<input type = "Confirm Submission" value = "Confirm Deletion of Doctor?">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>5.) Update the Name of a Hospital:</h5>
<form action = "hospital_update.php" method = "post">
Select the Hospital to be Updated: <br>
<input type = "radio" name = "hospital" value = "BBC">St. Joseph, London<br>
<input type = "radio" name = "hospital" value = "ABC">Victoria, London<br>
<input type = "radio" name = "hospital" value = "DDE">Victoria, Victoria<br>
Updated Hospital Name: <input type = "text" name = "hospname"><br>
<p>
<input type = "Confirm Submission" value = "Update">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>6.) List for Hospital and Head Doctor Information:</h2>
<form action = "get_hospital.php" method = "post">
<input type = "Confirm Submission" value = "See List">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>7.) Find a Patient (Using their OHIP Number):</h3>
<form action = "get_patient.php" method = "post">
Enter OHIP Number: <input type = "int" name = "patient"><br>
<p>
<input type = "Confirm Submission" value = "Search for Patient">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>8-a.) Assign Treatment (Choose a Doctor to Treat a Patient):</h2>
<form action = "assign_treatment.php" method = "post">
<ol>
<?php
	echo 'First - Select a Doctor:';
	$query = 'SELECT * FROM doctor';
	$result = mysqli_query($connection,$query);
    if (!$result) 
	{
         die("Error - the 2nd database query has failed.");
    }
    while ($row=mysqli_fetch_assoc($result)) 
	{
        echo '<li>';
        echo '<input type = "radio" name = "doctor" value = "';
        echo $row["licenumb"];
        echo '">' . $row["fname"] . " " . $row["lname"] . "<br>";
    }
    mysqli_free_result($result);
?>
</ol>
<ol>
<?php
	echo 'Second - Select a Patient to be Treated:';
	$query = 'SELECT * FROM patient';
	$result = mysqli_query($connection,$query);
    if (!$result) 
	{
         die("Error - the 2nd database query has failed.");
    }
    while ($row=mysqli_fetch_assoc($result)) 
	{
        echo '<li>';
        echo '<input type = "radio" name = "patient" value = "';
        echo $row["ohip"];
        echo '">' . $row["fname"] . " " . $row["lname"] . "<br>";
    }
    mysqli_free_result($result);
?>
</ol>
<input type = "Confirm Submission" value = "Assign">
</form>
<h2>8-b). Stop a Doctor From Treating a Patient:</h2>
<form action = "stop.php" method = "post">
<ol>
<?php
	echo 'Select the Doctor to Cease Treatment:';
	$query = 'SELECT * FROM doctor';
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
<ol>
<?php
   echo 'Select a Patient to Stop Being Treated:';
   $query = 'SELECT * FROM patient';
   $result = mysqli_query($connection,$query);
    if (!$result) 
	{
         die("Error - the 2nd database query has failed.");
    }
    while ($row = mysqli_fetch_assoc($result)) 
	{
        echo '<li>';
        echo '<input type = "radio" name = "patient" value = "';
        echo $row["ohip"];
        echo '">' . $row["fname"] . " " . $row["lname"] . "<br>";
    }
    mysqli_free_result($result);
?>
</ol>
<input type = "Confirm Submission" value = "Stop">
</form>

<h3>__________________________________________________________________________________________</h3>
<h2>9.) List of Available Doctor's with No Patients:</h2>
<form action = "get_available_doctor.php" method = "post">
<input type = "Confirm Submission" value = "Search">
</form>
<?php
mysqli_close($connection);
?>
</body>
</html>
