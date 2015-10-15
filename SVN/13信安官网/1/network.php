<?php 

	if (isset($_GET['networkid']) && isset($_GET['networkname'])) {
		
	$name = iconv("utf-8", "gb2312", $_GET['networkname']);
	//echo urlencode(iconv('UTF-8', 'GB2312', $_GET['networkname']));
	$id = $_GET['networkid'];

	$cookie_file = tempnam('./tmp', 'cookie');
	$url = "http://netcweb.jnu.edu.cn/zhwl/login.asp";
	$post_fields = 'id_num='.$id.'&u_name='.$name.'&Submit=%CC%E1%BD%BB';

	$ch = curl_init($url);
	curl_setopt($ch, CURLOPT_HEADER, 0); //头部
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_POST, true);
	curl_setopt($ch, CURLOPT_COOKIEJAR, $cookie_file);
	curl_setopt($ch, CURLOPT_POSTFIELDS, $post_fields);

	echo $output = curl_exec($ch);
	curl_close($ch);

	}



?>