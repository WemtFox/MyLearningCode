<?php 
	header('Content-type:text/html; charset=utf-8');
	include_once("../sql/sql.php");
	$sql = new SQL();
    $row = $sql->get_hw();
    $row = $row['0'];

	$probability1 = $_POST["probability1"];
	$probability2 = $_POST["probability2"];
	$db1 = $_POST["db1"];
	$db2 = $_POST["db2"];
	$discrete1 = $_POST["discrete1"];
	$discrete2 = $_POST["discrete2"];
	$english1 = $_POST["english1"];
	$english2 = $_POST["english2"];
	$digi1 = $_POST["digi1"];
	$digi2 = $_POST["digi2"];

    if($probability1 == NULL) $probability1 = $row["probability1"]; 
    if($probability2 == NULL) $probability2 = $row["probability2"];
    if($db1 == NULL) $db1 = $row["db1"];
    if($db2 == NULL) $db2 = $row["db2"];
    if($discrete1 == NULL) $discrete1 = $row["discrete1"];
    if($discrete2 == NULL) $discrete2 = $row["discrete2"];
    if($english1 == NULL) $english1 = $row["english1"];
    if($english2 == NULL) $english2 = $row["english2"];
    if($digi1 == NULL) $digi1 = $row["digi1"];
	if($digi2 == NULL) $digi2 = $row["digi2"];
	
	if($sql->update_hw($probability1, $probability2, $db1, $db2, $discrete1, $discrete2, $english1, $english2,$digi1,$digi2)){
	$sql ->insert_hw($probability1, $probability2, $db1, $db2, $discrete1, $discrete2, $english1, $english2,$digi1,$digi2);
	echo "<h1 align=\"center\">更新作业成功</h1>";
	}
	else{
	echo "<h1 align=\"center\">更新作业失败</h1>";
	}
 ?>