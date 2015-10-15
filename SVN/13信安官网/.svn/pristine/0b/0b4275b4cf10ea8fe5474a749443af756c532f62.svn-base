<?php
 header('Content-type:text/html; charset=utf-8');
 $s= new SaeStorage();
 $domain = 'datastructure';
 $name =$_FILES['file']['name'];
 $destFileName = "expert5/".$_FILES['file']['name'];
 $srcFileName = $_FILES['file']['tmp_name'];

 if($result = $s->upload($domain,$destFileName, $srcFileName))
 echo "上传成功"; 
 else
 echo "上传失败";
?>