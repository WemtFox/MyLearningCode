<?php
 header('Content-type:text/html; charset=utf-8');
if ($_SERVER['REQUEST_METHOD'] == 'POST'){}
 $s= new SaeStorage();
 $domain = 'datastructure';
 $name =$_FILES['file']['name'];
 $destFileName = "expert3/".$_FILES['file']['name'];
 $srcFileName = $_FILES['file']['tmp_name'];

 if($result = $s->upload($domain,$destFileName, $srcFileName))
 echo "上传成功"; 
 else
 echo "上传失败";
 }

 if(isset($_GET['key']))  
{  
    //header('Content-Type:application/json; charset=utf-8' ) ;  
    // Retrieve the status using the getStatus() function below  
    //echo json_encode(getStatusAPC());  
    echo json_encode(getStatusAPC());  
}  
function getStatusAPC()  
{  
    $response=false;  
    if($status = apc_fetch('upload_'.$_GET['key'])) {  
          
        $response=apc_fetch('upload_'.$_GET['key']);  
          
    }  
    return $response;  
}  
?>