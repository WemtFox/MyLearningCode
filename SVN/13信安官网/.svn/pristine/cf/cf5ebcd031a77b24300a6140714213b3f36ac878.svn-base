<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>无标题文档</title>
</head>

<body>

      <table width="720px" border="0" align="center" cellpadding="5" cellspacing="1" bgcolor="#add3ef">
      <td colspan="2" align="center">看看你们的留言</td>
      <?php 
      require("../sql/connect.php");
      $sql = "select * from advice order by time desc;";
      $query = @mysql_query($sql, $data);
      while ($row = @mysql_fetch_array($query)) {
      ?>  
      <tr bgcolor="#eff3ff">
      <td>建议对象：<?=$row[object] ?></td>  <td>时间：<?=$row[time]?></td>
      </tr>
      <tr bgColor="#ffffff">
      <td colspan="2">内容：<?=$row[advice]?></td>
      </tr>
      <? 
      }
      ?>
      </table>
      
</body>
</html>
