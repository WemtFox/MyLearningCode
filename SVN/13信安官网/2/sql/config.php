<?php 

/**
* 配置文件
*/

	//定义数据库连接参数
	define (DB_HOST, SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT);	
	define (DB_USER, SAE_MYSQL_USER);
	define (DB_PWD, SAE_MYSQL_PASS);
	define (DB_NAME, SAE_MYSQL_DB);


class DBSQL{

	protected $link;

	function __construct() {
			$link = mysql_connect(DB_HOST, DB_USER, DB_PWD) or die('fail!').mysql_error();
			if (mysql_select_db(DB_NAME)) $this->link = $link;
			mysql_query("set names 'utf8'",$this->link); 
			mysql_query("set time_zone = '+8:00';");	
	}

	public function select($sql = ''){

			if(empty($sql)) return false;

			$result = mysql_query($sql, $this->link);

			if(empty($result)) return false;

			$data =array();

			while ($row = @mysql_fetch_array($result,MYSQL_ASSOC)) {
				$data[] = $row;
			}

			return $data;	
		}

		public function insert($sql = ''){
			if(empty($sql)) return false;
			$result = mysql_query($sql, $this->link);
			return $result;
		}

		public function update($sql=''){
			if(empty($sql)) return false;
			$result = mysql_query($sql, $this->link);
			return $result;
		}

		public function delete($sql=''){
			if(empty($sql)) return false;
			$result = mysql_query($sql, $this->link);
			return $result;
		}


		function __destruct() {
			if (is_resource($this->link)) mysql_close($this->link);
		}
	}

 ?>