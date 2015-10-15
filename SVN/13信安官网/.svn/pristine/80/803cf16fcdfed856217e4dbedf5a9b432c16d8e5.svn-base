<?php
	header('Content-type:text/html; charset=utf-8');
	set_time_limit(120);
	include("../sql/sql.php");
	$sql = new Sql();
	$s= new SaeStorage();
	$subject = $_GET['subject'];
	$num = $_GET['num'];
	$domain = 'datastructure';
	$name =$_FILES['file']['name'];
	$destFileName = $subject.$num."/".$_FILES['file']['name'];
	$srcFileName = $_FILES['file']['tmp_name'];

	if($result = $s->upload($domain,$destFileName, $srcFileName)){
	echo "<script>alert(\"恭喜你，上传成功，自己做才好哦\");</script>";
	$sql->upload_exper($name, $subject, $num); 
	}
	else
	echo "<script>alert(\"sorry,上传失败！！,文件一般不可以大于10M哦\");</script>";
	$result = $sql->show_exper($subject, $num);
?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1 user-scalable=no, maximum-scale=1, minimum-scale=1">
<title>交作业就在这里交吧</title>
<link rel="stylesheet" href="http://cdn.bootcss.com/bootstrap/3.3.0/css/bootstrap.min.css">
<script src="http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js"></script>
<script src="http://cdn.bootcss.com/bootstrap/3.3.0/js/bootstrap.min.js"></script>
</head>
<body>
<div class="row">
		<div class="col-xs-10 col-md-6 col-md-offset-3">
		<table class="table table-striped">
			<Caption style="font-size:20px;text-align:center;">已交作业的如下</Caption>
			<tr> <td>交作业时间</td> <td>交作业时候的文件命名</td></tr>
			  <?php 	
			  foreach ($result as $row) {		
			  ?>
		  	<tr><td><?=$row['time']?></td> <td><?=$row['name']?></td></tr>
		  	  <?php 	
			  }		
			  ?>
		</table>
		</div>
</div>
</body>
</html>