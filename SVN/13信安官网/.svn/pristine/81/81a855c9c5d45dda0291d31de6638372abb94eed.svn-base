<?php 
header('Content-type:text/html; charset=utf-8');
$a = $_POST["object"];
$b = $_POST["advice"];

//连接mysql
$data = mysql_connect(SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);

//发送查询
if($data)
{
    mysql_select_db(SAE_MYSQL_DB,$data);
    //your code goes here



//接受POST数据

$sql = "insert into advice (object,advice) values ('".$a."','".$b."')";

//echo $sql;

if(mysql_query($sql,  $data))

echo "谢谢你的建议！";
else echo "留言失败╮(╯▽╰)╭！";

}

else echo "留言失败╮(╯▽╰)╭！";

?>