<?php  
	$subject = $_GET['subject'];
	$num = $_GET['num'];
	if($subject == 'digi') $here = '数字逻辑';
	elseif ($subject == 'datast') {
		$here = '数据结构';
	}
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

<div class="container" >
	<h1 align="center"><?=$here?>报告交这里</h1>
	<form role="from"  action="./upload_handle.php?subject=<?=$subject?>&num=<?=$num?>" method="post" enctype="multipart/form-data">
		<div class="row">
			<div class="col-xs-10 col-md-6 col-md-offset-3">
				<div class="form-group">
					<h1><small>注意:这里是实验<?=$num?></small></h1>
				    <label for="exampleInputFile">点击"选择文件"按钮上传文件:</label>
				    <input type="file" name="file" id="file">
				</div>
				<button type="submit" class="btn btn-default" onclick="check_file()">点击提交上传</button>
				<span class="help-block">注:1.一定要写好格式：姓名_学号_实验几</span>	
			</div>
		</div>			
	</form>	


<?php  
  	include("../sql/sql.php");
  	$sql = new Sql();
    $result = $sql->show_exper($subject, $num);
?>

	<div class="row">
		<div class="col-xs-10 col-md-6 col-md-offset-3">
		<table class="table table-striped">
			<Caption style="font-size:20px;text-align:center;">已交作业的如下</Caption>
			<tr> <td>交作业时间</td> <td>交作业时候的文件命名</td></tr>
			  <?php 	
			  foreach ($result as $row) {		
			  ?>
		  	<tr><td><?=$row['time']?></td> <td><?=$row['name']?></td>></tr>
		  	  <?php 	
			  }		
			  ?>
		</table>
		</div>
	</div>
</div>

<script>
	function check_file()
    {
      var x=document.getElementById("file").value;
      if(x==""){
        alert("还没选择文件呢");
        return false;
       }
    }
</script>
</body>
</html>