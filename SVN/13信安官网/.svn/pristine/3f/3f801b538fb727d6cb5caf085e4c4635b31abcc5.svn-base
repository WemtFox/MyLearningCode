<?php  

	include_once("config.php");
/**
* 13信安--数据库处理类
*/
class SQL extends DBSQL
{

	//更新作业
	public function update_hw($week, $probability1, $probability2, $db1, $db2, $discrete1, $discrete2, $english1, $english2, $digi1, $digi2)
	{
		$sql = "UPDATE update_hw SET week='".$week."',probability1='".$probability1."',probability2='".$probability2."',db1='".$db1."',db2='".$db2."',discrete1='".$discrete1."',discrete2='".$discrete2."',english1='".$english1."',english2='".$english2."',digi1='".$digi1."',digi2='".$digi2."'  WHERE id = 1";
		return $this->update($sql);
	}

	//插入作业
	public function insert_hw($week, $probability1, $probability2, $db1, $db2, $discrete1, $discrete2, $english1, $english2, $digi1, $digi2)
	{
		$sql = "INSERT INTO update_hw (week, probability1,probability2,db1,db2,discrete1,discrete2,english1,english2,digi1,digi2) VALUES ('".$week."','".$probability1."','".$probability2."','".$db1."','".$db2."','".$discrete1."','".$discrete2."','".$english1."','".$english2."','".$digi1."','".$digi2."')";
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
		$sql = "INSERT INTO `update_notice` (class_notice) VALUES ('".$class_notice."')";
		return $this->insert($sql);
	}

	//获取最新作业
	public function get_hw()
	{
		$sql="SELECT * FROM `update_hw` WHERE id = 1"; 
		return $this->select($sql);
	}

	//获取全部作业
	public function get_allhw($term = TERM)
	{
		$sql="SELECT * FROM `update_hw` WHERE id <> 1 AND term = $term order by id desc"; 
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
		$sql = "SELECT * FROM `update_notice` WHERE id <> 1 order by time desc";
		return $this->select($sql);
	}
	public function get_notice_page($page=1)
	{
		$sql = "SELECT * FROM `update_notice` WHERE id <> 1 order by time desc limit '".$page."',5";
		return $this->select($sql);
	}

	//交实验报告
	public function upload_exper($name, $subject, $num)
	{
		$sql = "INSERT INTO `exper_report` (name, subject, num) VALUES ('".$name."','".$subject."','".$num."')";
		return $this->insert($sql);
	}

	//展示已交的
	public function show_exper($subject, $num)
	{
		$sql = "SELECT * FROM `exper_report` WHERE subject='".$subject."' and num ='".$num."' order by time desc";
		return $this->select($sql);
	}






}


?>