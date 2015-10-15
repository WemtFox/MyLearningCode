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
							<li><a href="http://study.jnu.edu.cn/" target="_blank">study平台</a>
                            </li>
							<li><a href="http://202.116.24.4/nc/" target="_blank">计算机网络平台</a>
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
                    <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown">保不挂网站<span class="caret"></span></a>
                        <ul class="dropdown-menu" role="menu">
                        
                            <li><a href="http://www.mega2.cn/" target="_blank" title="">马克思基本原理概论</a>
                            </li>
                            <li><a href="http://www.mega2.cn/forum" target="_blank" title="">马克思基本原理概论论坛</a>
                            </li>
                        </ul>
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
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;计算机网络</li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["probability1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["probability2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;信息安全数学基础</li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["db1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw["db2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;操作系统原理
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "discrete1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "discrete2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning"><span class="glyphicon glyphicon-send"></span>&nbsp;数字图像处理</li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "english1"] ?>
                            </li>
                            <li class="list-group-item"><span class="glyphicon glyphicon-info-sign"></span>
                                <?=$hw[ "english2"] ?>
                            </li>
                            <li class="list-group-item list-group-item-warning">
                            <span class="glyphicon glyphicon-send"></span>&nbsp;马克思主义基本原理概论</li>
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

    <!--底部-->
    <div class="wrap">
    <footer class="footer" >
        <div class="container" style="background:#E9E9E9;margin-top:30px">
            <div class="row" style="width:100%">

                <div class="col-lg-3 col-xs-12">
                    <!-- <h1>联系我们</h1>
                    <address>
                        <p>Address: 暨南大学珠海校区</p>
                        <p>QianShan, ZhuHai</p>
                        <p>Phone : 13570618874</p>
                        <p>WeChat Public Account : 珠海暨大计协</p>
                        <p>Email : <a href="mailto:13570618874@163.com">13570618874@163.com</a></p>
                        <p>关于我们：紧跟计算机世界的最新潮流，给你最新的体验，我们互相学习，互相帮助。想要什么学习资源，基本都有，只要你有那颗炽热的心，高涨的学习热情,希望暨大的更多有能力或想自学成才的牛人加入建设这个在学校不是很出名的社团，让他成为暨大的唯一，成为各个初进大学的新生们首选的社团。</p>
                    </address> -->
                </div>
                <div class="col-lg-5 col-xs-12">
                    <h1>网站推荐</h1>
                    <div class="col-xs-6">
                      <ul class="list-unstyled">
                        <li><a href="http://study.163.com/" target="_blank">网易云课程</a>
                              </li>
                              <li><a href="http://open.163.com/" target="_blank">网易公开课</a>
                              </li>
                              <li><a href="http://www.51zxw.net/" target="_blank">51自学网</a>
                              </li>
                              <li><a href="http://wenku.baidu.com/course/index" target="_blank">百度课程</a>
                              </li>
                              <li><a href="http://www.68ps.com/zt/cs6/" target="_blank">PS联盟</a>
                              </li>
                              <li><a href="http://ke.qq.com/" target="_blank">腾讯课堂</a>
                              </li>
                              <li><a href="http://www.icourse163.org/" target="_blank">中国MOOC</a>
                              </li>
                              <li><a href="http://bbs.pceva.com.cn/" target="_blank">电脑知识</a>
                              </li>
                              <li><a href="http://www.android-study.net/" target="_blank">安卓学习网</a>
                              </li>
                              <li><a href="http://www.ucai.cn/index" target="_blank">优才网</a>
                              </li>
                              <li><a href="http://hero.csdn.net/" target="_blank">英雄会</a>
                              </li>
                              <li><a href="http://wanbiancheng.com/" target="_blank">玩编程</a>
                              </li>
                      </ul>
                    </div>

                    <div class="col-xs-6">
                      <ul class="list-unstyled">
                            <li><a href="http://www.w3school.com.cn/index.html" target="_blank">W3school</a>
                            </li>
                            <li><a href="http://www.imooc.com/" target="_blank">慕课网</a>
                            </li>
                            <li><a href="http://www.fenby.com/index" target="_blank">Fenby(粉笔)</a>
                            </li>
                            <li><a href="http://www.zixue.it/" target="_blank">自学IT网</a>
                            </li>
                            <li><a href="http://gkk.cn/" target="_blank">IT公开课</a>
                            </li>
                            <li><a href="http://www.maiziedu.com/" target="_blank">麦子学院</a>
                            </li>
                            <li><a href="http://www.kaikeba.com/" target="_blank">开课吧</a>
                            </li>
                            <li><a href="http://www.duobei.com/" target="_blank">多贝公开课</a>
                            </li>
                             <li><a href="http://see.xidian.edu.cn/cpp/" target="_blank">C语言中文网</a>
                            </li>
                            <li><a href="http://code4app.com/" target="_blank">Code4App</a>
                            </li>
                            <li><a href="http://www.eoeandroid.com/portal.php" target="_blank">eoe社区</a>
                            </li>
                            <li><a href="http://www.51cto.com/" target="_blank">51CTO</a>
                            </li>
                      </ul>
                    </div>
                    
                </div>
                <div class="col-lg-3 col-xs-6 col-lg-offset-1">
                    <!-- <h1>待思考区</h1>
                    <ul class="social-link-footer list-unstyled">
                        <li><a href="#"><i class="icon-facebook"></i></a></li>

                    </ul> -->
                </div>
            </div>
        </div>
    </footer>
    </div>

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