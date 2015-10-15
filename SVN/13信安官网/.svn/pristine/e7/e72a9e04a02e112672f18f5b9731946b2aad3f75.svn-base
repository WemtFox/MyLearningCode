<?php  

	$s= new SaeStorage();
	$domain = 'images';
	$destFileName = 'notices/'.$_FILES['file']['name'];
	$srcFileName = $_FILES['file']['tmp_name'];

	if($result = $s->upload($domain,$destFileName, $srcFileName)){
		echo $file_url =  $s->getUrl( $domain , $destFileName); 
	}else{
		echo "上传失败";
	}



?>