<?php
session_start();


if(isset($_POST['submit']))
{
   
    
    $hospital=$_POST['hospital'];
                $organ=$_POST['organ'];
                $Doc=$_POST['Doc'];


  $con = new MongoClient();

  if($con)
  {
    

    $database=$con->organ;
    $collection=$database->receiverinfo;
    

    $data=array('hospital'=>$hospital,'Doc'=>$Doc);
    $data1=array('organ'=>$organ);

   
    $collection->update (array("email" => $_SESSION['email'] ), array ('$set' => $data));
  
    $collection->update (array("email" => $_SESSION['email'] ), array ('$set' => $data1));
    


  }


}

session_destroy();

?>


<!DOCTYPE html>
	<html lang="en">
	<html>


	<head>
	
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	
	<!-- Latest compiled and minified CSS -->
		<link rel="stylesheet" href="bootstrap-3.3.7/css/bootstrap.min.css">

	<!-- jQuery library -->
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
		<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	
	<!-- Latest compiled JavaScript -->
		<script src="bootstrap-3.3.7/js/bootstrap.min.js"></script>
		
	<!-- W3.CSS is a modern CSS framework -->		
		<link rel="stylesheet" href="w3.css">
	
</head>
<body>

<div class="container-fluid">

<h4> Thank You for Registration as a Receiver.....!!  We Contact you as Soon as..!! </h4>
<br>

<label> For More Information Here:- </label> 
<input type="button" value="Login"  class="btn btn-default" onclick="window.location.href='ReceiverLogin.php'">

</div>
</body>

</body>
</html>




