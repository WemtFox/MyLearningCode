<?php 
    include( "./sql/sql.php"); 
    $sql = new SQL();
    $row = $sql->get_hw();
    $hw = $row['0'];
    $row = $sql->get_notice();
    $row_notice = $row['0'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
    <meta name="baidu-tc-verification" content="31244e037605b298d92c198bb4ccc2ad" />
    <meta name="baidu-site-verification" content="HefW3xjhv7" />
    <meta name="keywords" content="13信安作业网，信安，信息安全">
    <meta name="description" content="公布作业，通知，交作业等">
    <meta name="author" content="giantbranch,陆巨枝">
    <meta name="viewport" content="width=device-width, initial-scale=1 user-scalable=no, maximum-scale=1, minimum-scale=1" />
    <title>13信安作业</title>
    <link rel="stylesheet" type="text/css" href="index.css">
    <script type="text/javascript" src="check_advice.js"></script>
    <!--<script src="http://siteapp.baidu.com/static/webappservice/uaredirect.js" type="text/javascript"></script>
    <script type="text/javascript">uaredirect("http://siteapp.baidu.com/webapp/13xinanzuoye.sinaapp.com","http://13xinanzuoye.sinaapp.com");</script>-->
</head>

<body style="background: #F2F2F2;">
    <div class="container">
        <!--顶部图片-->
        <div class="header">
            <img src="./images/13xinan.jpg" alt="13信安官网">
        </div>
        <!--导航-->
        <div class="navigation">
            <ul id="nav">
                <li><a href="http://13xinanzuoye.sinaapp.com/">首页</a>
                </li>
                <li><a href="./before/hwBefore.html">作业回顾</a>
                </li>
                <li><a href="./before/tongBefore.html">通知回顾</a>
                </li>
                <li><a href="http://pan.baidu.com/s/1pJr1PwR" target="_blank">课件下载</a>
                </li>
                <li><a href="http://www.jnu.edu.cn/jnu2014/" target="_blank">暨大官网</a>
                </li>
                <li><a href="http://202.116.0.176/" target="_blank">综合教务系统</a>
                </li>
                <form action="http://www.baidu.com/baidu" target="_blank" align="right">
                    <input name=tn type=hidden value=baidu>
                    <input type=text name=word size=30>
                    <input type="submit" value="百度搜索">
                </form>
            </ul>
        </div>
        <!--网站主体-->
        <div class="main">
            <!--主体左部分-->
            <div class="lside">
                <!--作业框-->
                <div class="four"> <span class="bea_title">第十三.四周作业</span>
                    <ul>
                        <li><span class="tltle">概率论</span>
                        </li>
                        <li>单:
                            <?=$hw[ "probability1"] ?>
                        </li>
                        <li>双:
                            <?=$hw[ "probability2"] ?>
                        </li>
                        <li><span class="tltle">数据结构实验</span>
                        </li>
                        <li>单:
                            <?=$hw[ "db1"] ?>
                        </li>
                        <li>双:
                            <?=$hw[ "db2"] ?>
                        </li>
                        <li><span class="tltle">离散</span>
                        </li>
                        <li>单:
                            <?=$hw[ "discrete1"] ?>
                        </li>
                        <li>双:
                            <?=$hw[ "discrete2"] ?>
                        </li>
                        <li><span class="tltle">英语</span>
                        </li>
                        <li>单:
                            <?=$hw[ "english1"] ?>
                        </li>
                        <li>双:
                            <?=$hw[ "english2"] ?>
                        </li>
                    </ul> <span style="font-size:14px;font-weight:bold">更新时间:<?=$hw["time"]?></span>
                </div>
                <!--通知框-->
                <div class="four">
                    <span class="bea_title">通知</span>
                    <div> 
                    <span style="color:red;font_weight:blod;text-align:center;font-side:18px;">数字逻辑实验</span>
                        <a href="http://pan.baidu.com/s/1eQCJsKq" target="_blank">(数字逻辑实验资料下载)</a>
                    <span style="color:red;font_weight:blod;text-align:center;font-side:18px;">NEW</span>    
                        <li>1.习题都n年没碰过了,赶紧补吧</li>
                        <li>2实验1.2.3下次课交（实验3要纸质版，其他电子版）</li>
                    </div>
                    <div class="cla_notice" style="padding:0px 5px">
                     <span style="color:red;font_weight:blod">↓↓↓↓↓</span>
                        班级通知 <span style="color:red;font_weight:blod">↓↓↓↓↓</span>
                    </div> 
                    <span style="padding:0px 5px"><?=$row_notice["class_notice"]?></span><br>
                    <span style="font-size:14px;font-weight:bold;padding:0px 5px">
                    更新时间:<?=$row_notice["time"]?></span>
                </div>
                <!--清除浮动-->
                <div class="clr"></div>
                <!--意见反馈框-->
                <div class="footer">
                    <form action="./advice/show_advice.php" method="post" name="form_advice" onsubmit="return check_advice()" target="_blank">
                        <table>
                            <tr>
                                <td>对
                                    <select name="object">
                                        <option>网站</option>
                                        <option>老师</option>
                                        <option>班级</option>
                                        <option>其他</option>
                                    </select>的建议：</td>
                                <td>
                                    <textarea name="advice" id="advice"></textarea>
                                </td>
                                <td>
                                    <input type="submit" value="提交请点我">
                                    <br>
                                </td>
                            </tr>
                            <tr>
                                <td colspan="3"><a href="./advice/show_advice_list.php" target="_blank">查看同学们的无厘头建议请点我</a>
                                </td>
                            </tr>
                        </table>
                    </form>
                </div>
            </div>
            <!--lside末标签-->
            <!--主体右边-->
            <div class="rside">
                <div class="two"> <span class="bea_title">数据结构交作业专区</span>
                    <br>
                    <div class="datahw">
                        <a href="./upload/close.html" target="_blank">实验七(P43 6.51)</a>
                        <br> <a href="./upload/close.html" target="_blank">实验八(6.37 6.38 6.39)</a>
                        <br> <a href="./upload/close.html" target="_blank">实验九(深度&广度优先搜索)</a> 
                        <br> <a href="./upload/exper10.html" target="_blank">实验十(实验1-9大集合)</a> 
                        <br> <a href="./upload/exper11.html" target="_blank">实验1--9补交专用</a>
                        <br>
                    </div>
                    <!--<div class="remind">注:1.一定要写好格式：<big><b>姓名_学号_实验几</b></big>（如果要提交多次,<b>文件名和上一个相同即可替换原来的）</b>
                        <br>2.如果写成了多个word文档，请压缩到一个压缩包再交上来
                        <br>3.<big><b>每周四上早课前30分钟截止（那时我从服务器下载）</b></big>
                    </div>-->
                    <span class="bea_title">数字逻辑交作业专区</span>
                    <div class="datahw">
                        <br> <a href="./upload/digi_close.html" target="_blank">实验指导1</a> 
                        <br> <a href="./upload/digi_close.html" target="_blank">实验指导2</a> 
                        <br>
                    </div>
                    <div class="remind" >注:1. <span style="color:red;font_weight:blod">同样要写好格式：<big><b>姓名_学号_实验几</b></big></span>
                        <br>2.<b>现在已知实验3交纸质版，后面还有一个实验老师还没确认那个交纸质版</b>
                        <br>3. <big><b>2014/12/05星期五中午1点</b>截止！！！！！！</big>
                    </div>

                </div>
                <!--two尾-->
            </div>
            <!--rside尾-->
        </div>
        <!--main尾-->
    </div>
    <!--container尾-->
</body>

<script>
var _hmt = _hmt || [];
(function() {
  var hm = document.createElement("script");
  hm.src = "//hm.baidu.com/hm.js?95d073f8cfa69450998ff5a36a5fbe3c";
  var s = document.getElementsByTagName("script")[0]; 
  s.parentNode.insertBefore(hm, s);
})();
</script>


</html>