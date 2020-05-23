<?php
$conn=mysqli_connect('localhost','root','Chinmay@13','entries');
if(mysqli_connect_errno()){
	echo 'Failed to connect to MYSQL'.mysqli_connect_errno();
}
$query='SELECT * FROM person_details';
$result=mysqli_query($conn,$query);
$posts=mysqli_fetch_all($result,MYSQLI_ASSOC);

mysqli_free_result($result);
if(isset($_POST['submit'])){
	$roll=$_POST['roll'];
	$name=$_POST['name'];
	$query ="INSERT INTO person_details(roll_no,name) VALUES('$roll','$name')";
	if(mysqli_query($conn,$query)){
		header('Location: '.'http://localhost/php%20sanbox/convener1.php/'.'');
	}else{
		echo 'Error'.mysqli_error($conn);
	}

}
mysqli_close($conn);

?>
<!DOCTYPE html>
<html>
<head>
	<title>Person Details</title>
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" >
</head>
<body>

	<h1>Enter details below</h1>
	<form method="POST" action="<?php $_SERVER['PHP_SELF'];?>">
	
		<label>Roll Number</label>
		<br>
		<input type="number" name="roll">
		<br>
		<label>Name</label>
		<br>
		<input type="text" name="name" >
		<br><br>
		 <button type="submit" name="submit" value="submit" class="btn btn-primary">Submit</button>
		
	</form>
	
		<h1 class="text-center">PERSON DATA</h1>
	<table class="table table-bordered">
  <thead>
    <tr>
      <th scope="col">Roll number</th>
      <th scope="col">Name</th>
     </tr>
  </thead>
  <tbody>
  	
  		<?php foreach($posts as $post):?>
  			<tr><td> <?php echo $post['roll_no'];?> </td>
  				<td> <?php echo $post['name'];?></td>
  			</tr>
  			
  		<?php endforeach;?>
  		
  
  </tbody>
</table>
		

	

</body>
</html>