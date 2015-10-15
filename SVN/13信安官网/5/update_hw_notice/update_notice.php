<?php 
	header('Content-type:text/html; charset=utf-8');
	include_once("../sql/sql.php");
	$sql = new SQL();

	$class_notice = $_POST["class_notice"];

	  
	if($class_notice == NULL){
		$row = $sql->get_notice();
		$row = $row['0']; 
		$class_notice = $row["class_notice"];  
	} 
	
	if($sql->update_notice($class_notice)){
		$sql->insert_notice($class_notice);
		echo "<h1 align=\"center\">更新班级通知成功</h1>";
	}
	else{
		echo "<h1 align=\"center\">更新班级通知失败</h1>";
	}
 ?>