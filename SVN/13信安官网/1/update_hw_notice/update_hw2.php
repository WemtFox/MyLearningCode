<?php 
    include( "../sql/sql.php"); 
    $sql = new SQL();
    $row = $sql->get_hw();
    $hw = $row['0'];
?>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>更新作业</title>
<!-- Bootstrap -->
    <link rel="stylesheet" href="http://cdn.bootcss.com/bootstrap/3.3.0/css/bootstrap.min.css">
    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="http://cdn.bootcss.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="http://cdn.bootcss.com/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="http://cdn.bootcss.com/jquery/1.11.1/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="http://cdn.bootcss.com/bootstrap/3.3.0/js/bootstrap.min.js"></script>
    <script type="text/javascript">
        $("document").ready(function(){
            var url = "getWeek.php";
            var data = {};
            $.getJSON(url,data,function(res){
                $("#week").val(res.week);
            });
        });
    </script>
</head>

<style type="text/css">
textarea{
	margin: 10px 0;
}
</style>

<body>


<div class="container">

<form role="from" action="update_hw.php" method="post">

<div class="form-group">

<input type="text" class="form-control" id="week" name="week" placeholder="请输入周数" value="第周作业">

<h1><small>计算机网络</small></h1>
<textarea class="form-control" rows="2" name="probability1" placeholder="单周"><?=$hw["probability1"] ?></textarea>
<textarea class="form-control" rows="2" name="probability2" placeholder="双周"><?=$hw["probability2"] ?></textarea>

<h1><small>信息安全数学基础</small></h1>
<textarea class="form-control" rows="2" name="db1" placeholder="单周"><?=$hw["db1"] ?></textarea>
<textarea class="form-control" rows="2" name="db2" placeholder="双周"><?=$hw["db2"] ?></textarea>

<h1><small>操作系统原理</small></h1>
<textarea class="form-control" rows="2" name="discrete1" placeholder="单周"><?=$hw[ "discrete1"] ?></textarea>
<textarea class="form-control" rows="2" name="discrete2" placeholder="双周"><?=$hw[ "discrete2"] ?></textarea>

<h1><small>数字图像处理</small></h1>
<textarea class="form-control" rows="2" name="english1" placeholder="单周"><?=$hw[ "english1"] ?></textarea>
<textarea class="form-control" rows="2" name="english2" placeholder="双周"><?=$hw[ "english2"] ?></textarea>

<h1><small>马克思主义基本原理概论</small></h1>
<textarea class="form-control" rows="2" name="digi1" placeholder="单周"><?=$hw[ "digi1"] ?></textarea>
<textarea class="form-control" rows="2" name="digi2" placeholder="双周"><?=$hw[ "digi2"] ?></textarea>
<h4>是否插入数据库</h4>
<input type="radio" class="form-control" name="save" value="1">是
<input type="radio" class="form-control" name="save" value="0" checked="checked">否


<button type="submit" class="btn btn-default btn-lg btn-block"  style="width:50%;margin:10px auto;">提交</button>
</div>



</form>


</div>

</body>
</html>