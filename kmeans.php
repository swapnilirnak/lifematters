<h4>Receiver's E-mails Are ::</h4>

<?php

session_start();



	unset($out);
	unset($result);
	  $patient = "bhau@gmail.com"; 
	  //$patient =$_SESSION['email'];                               
	exec("Rscript kmeans.R $patient", $out);

	$length = count($out);

	for ($i = 0; $i < $length; $i++)
{


		foreach (explode("\n", $out[$i]) as $row)
		
{

			if (strpos($row, ']') !== false)

				$numbersAsStr = substr($row, strpos($row, ']') + 1);

			else

				$numbersAsStr = $row;

	
		foreach (explode(' ', $numbersAsStr) as $potentialNumber)

			{

				if ($potentialNumber !== '')

				{

					$potentialNumber = trim($potentialNumber, '"');

					$result[] = $potentialNumber;

					
				}

			}
		}


//echo "Email Is : " .$out[$i];

echo "</br>";
echo "Email Is :: ".$result[$i];
echo "</br>";

}
$_SESSION['result']=$result;


//echo "Email IS ::" .$result[];
//echo"<br>";
//var_dump($result);
//echo"<br>";
/*$con = new MongoClient();

$database=$con->organ;
$collection=$database->kresult;

$collection->insert(array("email"=>$result));

$length = count($result);


for($j=0;$j<$length;$j++)
{

	echo "Email IS ::" .$result[$j];


}
*/
?>

<script type="text/javascript">
//window.location = "mm.php";
</script>








