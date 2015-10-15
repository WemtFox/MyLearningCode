<?php  
    include( "../sql/sql.php"); 
    $sql = new SQL();
    $result = $sql->get_allhw();
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
                    <li  class="active"><a href="./hwBefore.html">作业回顾</a>
                    </li>
                    <li><a href="./tongBefore.html">通知回顾</a>
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
    <!--作业回顾-->
    <div class="container" style="margin-top:70px;">
        <div class="row">
            <?php 
                foreach ($result as $hw) {
            ?>
            <div class="col-xs-12 col-md-4">
                <div class="panel panel-info" id="hw">
                    <div class="panel-heading"><span class="glyphicon glyphicon-bell"></span>&nbsp;<?=$hw['week']?></div>
                    <ul class="list-group">
                        <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;概率论</li>
                        <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                            <?=$hw[ "probability1"] ?>
                        </li>
                        <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                            <?=$hw[ "probability2"] ?>
                        </li>
                        <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;数据结构实验</li>
                        <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                            <?=$hw[ "db1"] ?>
                        </li>
                        <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                            <?=$hw[ "db2"] ?>
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
                    </ul>
                </div>
            </div>
            <?php 
                }
            ?>
        </div>
    </div>

</body>
</html>