<?php 


//连接mysql
$data = @mysql_connect(SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS);

//发送查询
if($data)
{
    @mysql_select_db(SAE_MYSQL_DB,$data);
    //your code goes here
}



?>