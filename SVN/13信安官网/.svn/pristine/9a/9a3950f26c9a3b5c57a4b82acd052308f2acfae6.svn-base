<?php 
    include( "./sql/sql.php"); 
    $sql = new SQL();
    $row = $sql->get_hw();
    $hw = $row['0'];
    $row = $sql->get_notice();
    $row_notice = $row['0'];
?>

<!DOCTYPE html>
<html>
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

<style type="text/css">
li{
     list-style:none;
}
</style>

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
                    <!--<li><a href="http://pan.baidu.com/s/1pJr1PwR" target="_blank">课件及试卷下载</a>
                    </li>-->
                    <li><a href="http://yunpan.cn/cQZ5A5yKqtSYV" target="_blank">课件及试卷下载(密码:e61e)</a>
                    </li>
                    <li class="dropdown"> <a href="#" class="dropdown-toggle" data-toggle="dropdown">暨大各种网站<span class="caret"></span></a>
                        <ul class="dropdown-menu" role="menu">
                            <li><a href="http://www.jnu.edu.cn/jnu2014/" target="_blank">暨大官网</a>
                            </li>
                            <li><a href="http://202.116.0.176/" target="_blank">综合教务管理系统</a>
                            </li>
                            <li><a href="http://202.116.1.182:9000/" target="_blank">课程评估专用</a>
                            </li><li><a href="http://career.jnu.edu.cn/" target="_blank">暨南大学就业指导服务平台</a>
                            </li>
                            <!-- <li class="divider"></li>
                            <li class="dropdown-header"></li>
                            
                            <li><a href="#"></a></li>-->
                        </ul>
                    </li>
                    <li><a href="http://cet.jnu.edu.cn/cet/" target="_blank">四六报名</a>
                    </li>
                    <li><a href="http://pan.baidu.com/s/1kT1hmTp" target="_blank" title="邹博提供">零基础入门学习汇编语言</a>
                    </li>

                </ul>
            </div>
            <!--/.nav-collapse -->
        </div>
    </nav>
    <!--通知栏-->
    <div class="container" style="margin-top:70px;">
        <div class="jumbotron" style="width:90%;margin:0 auto;padding:10px 20px;">
            <h3><b>通知</b></h3> 
            <p style="font-size:15px;">
                <?=$row_notice[ "class_notice"]?>
            </p>
            <p style="font-size:12px;"><i class="glyphicon glyphicon-time"></i>&nbsp;更新时间：
                <?=$row_notice[ "time"]?>
            </p>
        </div>
    
    
            <div class="row" style="width:90%;margin:0 auto;margin-top:20px;font-size:14px;">
                <!--公布作业-->
                <div class="col-xs-12 col-md-4">
                    <div class="panel panel-info" id="hw">
                        <div class="panel-heading"><span class="glyphicon glyphicon-bell"></span>&nbsp;<?=$hw["week"] ?></div>
                        <ul class="list-group">
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;LINUX高级编程</li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["probability1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["probability2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;信息安全导论</li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["db1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["db2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;Windows 编程<a href="http://pan.baidu.com/s/1i3H0NBn" target="_blank" class="pull-right">
                            MSDN下载<span class="badge">1</span></a>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "discrete1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "discrete2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;汇编</li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "english1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "english2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning">
                            <span class="glyphicon glyphicon-send"></span>&nbsp;JAVA</li>
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

                    
				<div class="col-xs-12 col-md-4">
					<div class="panel panel-info" id="exam">
						<div class="panel-heading"><span class="glyphicon glyphicon-bell"></span>&nbsp;实用功能</div>
							<div class="panel-body">
    							<form class="form-horizontal" method="GET" action="./network.php" target="_blank">
                                    <big><label>校园网上网的参数查询</label></big>
    							  <div class="form-group">
    								<div class="col-sm-10">
    								  <input type="text" class="form-control" id="studentNumber" name="networkid" placeholder="学号">
    								</div>
    							  </div>
    							  <div class="form-group">
    								<div class="col-sm-10">
    								  <input type="text" class="form-control" id="name" name="networkname" placeholder="姓名">
    								</div>
    							  </div>
    							  <div class="form-group">
    								<div class="col-sm-offset-2 col-sm-10">
    								  <button type="submit" class="btn btn-default">查询</button>
    								</div>
    							  </div>
    							</form>
						  </div>
					</div> 
				</div>
				
                <!--上传作业-->
                <div class="col-xs-12 col-md-4">
                    <div class="panel panel-info" id="upload">
                        <div class="panel-heading"><span class="glyphicon glyphicon-folder-open"></span>&nbsp;珠区教务通知</div>
                        <ul class="list-group"> 
                            <?php 
                                $url = 'http://zhjw.jnu.edu.cn/info.php?typ=1'; 
                                //1.初始化
                                $ch = curl_init();
                                //2.设置选项，包括URL
                                curl_setopt($ch, CURLOPT_URL, $url);
                                curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
                                curl_setopt($ch, CURLOPT_HEADER, 0);
                                //3.执行并获取HTML文档内的内容
                                $output = curl_exec($ch);
                                //检查错误，虽然不是必须的
                                if($output === FALSE){
                                    echo "cURL Error:".curl_error($ch);
                                }
                                //echo $output = iconv("gb2312//IGNORE", "utf-8", $output);
                                $output = iconv("gb2312//IGNORE", "utf-8", $output);
                                $listNumberStr = '/<li class="s_li">(.*?)<\/li>/i';    
                                preg_match_all($listNumberStr, $output, $list);
                                $list[0] = str_replace("article.php","http://zhjw.jnu.edu.cn/article.php",$list[0]);
                                for ($i=0; $i < 6; $i++) { 
                                    echo $list[0][$i];
                                }
                                //echo $output;
                                //4.释放curl句柄
                                curl_close($ch);
                            ?>
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
                        </form>
                    </div>
                </div>
            </div>
    </div><!--container-->

<script>
    
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