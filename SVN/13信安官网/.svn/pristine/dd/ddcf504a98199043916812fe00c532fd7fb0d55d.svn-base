<?php  

	include_once("config.php");
/**
* 13信安--数据库处理类
*/
class SQL extends DBSQL
{

	//更新作业
	public function update_hw($probability1, $probability2, $db1, $db2, $discrete1, $discrete2, $english1, $english2)
	{
		$sql = "UPDATE update_hw SET probability1='".$probability1."',probability2='".$probability2."',db1='".$db1."',db2='".$db2."',discrete1='".$discrete1."',discrete2='".$discrete2."',english1='".$english1."',english2='".$english2."' WHERE id = 1";
		return $this->update($sql);
	}

	//插入作业
	public function insert_hw($probability1, $probability2, $db1, $db2, $discrete1, $discrete2, $english1, $english2)
	{
		$sql = "INSERT INTO update_hw (probability1,probability2,db1,db2,discrete1,discrete2,english1,english2) VALUES ('".$probability1."','".$probability2."','".$db1."','".$db2."','".$discrete1."','".$discrete2."','".$english1."','".$english2."')";
		return $this->insert($sql);
	}

	//更新通知
	public function update_notice($class_notice)
	{
		$sql = "UPDATE update_notice SET class_notice='".$class_notice."' where id = 1";
		return $this->update($sql);
	}

	//插入通知
	public function insert_notice($class_notice)
	{
		$sql = "INSERT INTO update_notice (class_notice) VALUES ('".$class_notice."')";
	}

	//获取最新作业
	public function get_hw()
	{
		$sql="SELECT * FROM `update_hw` WHERE id = 1"; 
		return $this->select($sql);
	}

	//获取全部作业
	public function get_allhw()
	{
		$sql="SELECT * FROM `update_hw`"; 
		return $this->select($sql);
	}

	//获取最新通知
	public function get_notice()
	{
		$sql = "SELECT * FROM `update_notice` WHERE id = 1";
		return $this->select($sql);
	}

	//获取全部通知
	public function get_allnotice()
	{
		$sql = "SELECT * FROM `update_notice`";
		return $this->select($sql);
	}






}


?>