<?php 
      header('Content-type:text/html; charset=utf-8');
      $a = $_POST["object"];
      $b = $_POST["advice"];
      $a = strip_tags($a);
      $b = strip_tags($b);
      if($b != ""){
      require("../sql/connect.php");
      $sql = "insert into advice (object,advice) values ('".$a."','".$b."')";
      @mysql_query($sql,  $data);
      }
      ?>



      <table width="720px" border="0" align="center" cellpadding="5" cellspacing="1" bgcolor="#add3ef">
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
?>