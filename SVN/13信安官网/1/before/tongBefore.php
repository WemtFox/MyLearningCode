<?php  
    include( "../sql/sql.php"); 
    $sql = new SQL();
    $notice = $sql->get_allnotice();
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
                    <li><a href="../">首页</a>
                    </li>
                    <li><a href="./hwBefore.php">作业回顾</a>
                    </li>
                    <li class="active"><a href="./tongBefore.php">通知回顾</a>
                    </li>
                    <li><a href="http://pan.baidu.com/s/1pJr1PwR" target="_blank">课件下载</a>
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

      <?php 
        foreach ($notice as $row_notice) {
      ?>
        <div class="jumbotron" style="padding:10px 20px;">
            <h3><b>通知</b></h3> 
            <p style="font-size:15px;">
                <?=$row_notice["class_notice"]?>
            </p>
            <p style="font-size:12px;"><i class="glyphicon glyphicon-time"></i>&nbsp;更新时间：
                <?=$row_notice["time"]?>
            </p>
        </div>

      <?php 
        }  
      ?>
    </div>

     


</body>
</html>