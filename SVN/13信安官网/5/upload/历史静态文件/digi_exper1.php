<?php
 header('Content-type:text/html; charset=utf-8');
 $s= new SaeStorage();
 $domain = 'datastructure';
 $name =$_FILES['file']['name'];
 $destFileName = "digi_exper1/".$_FILES['file']['name'];
 $srcFileName = $_FILES['file']['tmp_name'];

 if($result = $s->upload($domain,$destFileName, $srcFileName))
 echo "<h1 align=\"center\">上传成功</h1>"; 
 else
 echo "<h1 align=\"center\">上传失败</h1>";
?>