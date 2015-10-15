<?php 
    include( "./sql/sql.php"); 
    $sql = new SQL();
    $row = $sql->get_hw();
    $hw = $row['0'];
    $row = $sql->get_notice();
    $row_notice = $row['0'];
?>

<!DOCTYPE html>

<head>
    <title>13信安官网</title>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <meta name="baidu-tc-verification" content="31244e037605b298d92c198bb4ccc2ad" />
    <meta name="baidu-site-verification" content="HefW3xjhv7" />
    <meta name="keywords" content="13信安作业网，信安，信息安全">
    <meta name="description" content="公布作业，通知，交作业等">
    <meta name="author" content="giantbranch--陆巨枝">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script type="text/javascript" src="check_advice.js"></script>
    <link href="http://cdn.bootcss.com/bootstrap/3.3.1/css/bootstrap.min.css" rel="stylesheet">
    <script src="http://cdn.bootcss.com/jquery/2.1.1/jquery.min.js"></script>
    <script src="http://cdn.bootcss.com/bootstrap/3.3.1/js/bootstrap.min.js"></script>
</head>

<body>
    <!--导航栏-->
    <nav class="navbar navbar-default navbar-fixed-top" role="navigation" style="margin-bottom:10px;">
        <div class="container">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar"> <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button> <a class="navbar-brand" href="#"><span class="glyphicon glyphicon-home"></span>&nbsp;13信安官网</a>
            </div>
            <div id="navbar" class="navbar-collapse collapse">
                <ul class="nav navbar-nav">
                    <li class="active"><a href="./">首页</a>
                    </li>
                    <li><a href="./before/hwBefore.php">作业回顾</a>
                    </li>
                    <li><a href="./before/tongBefore.php">通知回顾</a>
                    </li>
                    <li><a href="http://pan.baidu.com/s/1pJr1PwR" target="_blank">课件及试卷下载</a>
                    </li>
                    <li class="dropdown"> <a href="#" class="dropdown-toggle" data-toggle="dropdown">暨大各种网站<span class="caret"></span></a>
                        <ul class="dropdown-menu" role="menu">
                            <li><a href="http://www.jnu.edu.cn/jnu2014/" target="_blank">暨大官网</a>
                            </li>
                            <li><a href="http://202.116.0.176/" target="_blank">综合教务管理系统</a>
                            </li>
                            <li><a href="http://202.116.1.182:9000/" target="_blank">课程评估专用</a>
                            </li>
                            <!-- <li class="divider"></li>
                            <li class="dropdown-header"></li>
                            
                            <li><a href="#"></a></li>-->
                        </ul>
                    </li>
                </ul>
            </div>
            <!--/.nav-collapse -->
        </div>
    </nav>
    <!--通知栏-->
    <div class="container" style="margin-top:70px;">
        <div class="jumbotron" style="padding:10px 20px;">
            <h3><b>通知</b></h3> 
            <p style="font-size:15px;">
                <?=$row_notice[ "class_notice"]?>
            </p>
            <p style="font-size:12px;"><i class="glyphicon glyphicon-time"></i>&nbsp;更新时间：
                <?=$row_notice[ "time"]?>
            </p>
        </div>
    </div>
    <div class="row" style="width:90%;margin:0 auto;font-size:14px;">
        <!--公布作业-->
        <div class="col-xs-12 col-md-6">
            <div class="panel panel-info" id="hw">
                <div class="panel-heading"><span class="glyphicon glyphicon-bell"></span>&nbsp;<?=$hw["week"] ?></div>
                <ul class="list-group">
                    <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;概率论</li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw["probability1"] ?>
                    </li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw["probability2"] ?>
                    </li>
                    <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;数据结构实验</li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw["db1"] ?>
                    </li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw["db2"] ?>
                    </li>
                    <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;离散数学</li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw[ "discrete1"] ?>
                    </li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw[ "discrete2"] ?>
                    </li>
                    <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;英语</li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw[ "english1"] ?>
                    </li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw[ "english2"] ?>
                    </li>
                    <li class="list-group-item list-group-item-warning">
                    <span class="glyphicon glyphicon-send"></span>&nbsp;数字逻辑<a href="http://pan.baidu.com/s/1eQCJsKq" target="_blank" class="pull-right"><span class="glyphicon glyphicon-download-alt"></span>
                    实验资料下载<span class="badge">2</span></a></li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw[ "digi1"] ?>
                    </li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                        <?=$hw[ "digi2"] ?>
                    </li>
                    <li class="list-group-item"><span class="glyphicon glyphicon-time">&nbsp;更新时间：<?=$hw["time"]?></span>
                    </li>
                </ul>
            </div>
        </div>
        <!--上传作业-->
        <div class="col-xs-12 col-md-6">
            <div class="panel panel-info" id="upload">
                <div class="panel-heading"><span class="glyphicon glyphicon-folder-open"></span>&nbsp;数据结构交作业专区</div>
                <ul class="list-group"> 
                    <a href="./upload/close.html" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验十(实验1-9大集合)</a>
                    <a href="./upload/close.html" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验1--9补交专用</a>
                </ul>
                <div class="panel-heading"><span class="glyphicon glyphicon-folder-open"></span>&nbsp;数字逻辑交作业专区</div>
                <ul class="list-group"> 
                    <a href="./upload/upload.php?subject=digi&num=4" target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验指导4</a>
                    <a href="./upload/upload.php?subject=digi&num=5" target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验指导5</a>
                    <a href="./upload/upload.php?subject=digi&num=6" target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验指导6</a>
                    <a target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验指导7（纸质版，可打印）</a>
                    <a href="./upload/upload.php?subject=digi&num=8" target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;实验指导8</a>
                    
                    <!--<a href="./upload/digi_close.html" target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;</a>
                      <a href="./upload/digi_close.html" target="_blank" class="list-group-item" target="_blank"><span class="glyphicon glyphicon-chevron-right"></span>&nbsp;</a>
                      -->
                </ul>

                <ul>
                        <span style="color:red;font_weight:blod">1.同样要写好格式：<big><b>姓名_学号_实验几</b></big></span>
                        <br>2.<b>现在已知实验3交纸质版，后面还有一个实验老师还没确认那个交纸质版</b>

                </ul> 
                <div class="panel-heading"><span class="glyphicon glyphicon-hand-right"></span>&nbsp;意见反馈</div>
                <form role="from" action="./advice/show_advice.php" method="post" target="_blank">
                <div class="form-group">
                    <select class="form-control" name="object" id="object" style="width:90%;margin:10px auto;">         
                        <option>网站</option>
                        <option>老师</option>
                        <option>班级</option>
                        <option>其他</option>
                    </select>        
                </div>

                <div class="form-group">
                    <textarea class="form-control" rows="5" name="advice" id="advice" style="width:90%;margin:0 auto;" placeholder="请输入你的建议"></textarea>
                    <button type="submit" class="btn btn-default btn-lg btn-block" onclick="return check_advice()" style="width:90%;margin:10px auto;">提交</button>
                </div>
            </div>
        </div>
    </div>
<script>
    var explorer = window.navigator.userAgent;
    if (explorer.indexOf("MSIE") >= 0 || explorer.indexOf("Firefox") >= 0 || explorer.indexOf("Chrome") >= 0 || explorer.indexOf("Opera") >= 0 || explorer.indexOf("Safari") >= 0) {
        var h = document.getElementById("hw").offsetHeight > document.getElementById("upload").offsetHeight ? document.getElementById("hw").offsetHeight : document.getElementById("upload").offsetHeight
        document.getElementById("hw").style.height = document.getElementById("upload").style.height = h + "px"
    }
    var _hmt = _hmt || [];
    (function() {
      var hm = document.createElement("script");
      hm.src = "//hm.baidu.com/hm.js?95d073f8cfa69450998ff5a36a5fbe3c";
      var s = document.getElementsByTagName("script")[0]; 
      s.parentNode.insertBefore(hm, s);
    })();
</script>



</body>

</html>