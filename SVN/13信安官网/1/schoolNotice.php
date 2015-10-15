<?php  
include './Crawler/Snoopy.class.php';
define('URL', "http://i.jnu.edu.cn/dcp/forward.action?path=/portal/portal&p=home");

$cookie_file = tempnam('./tmp', 'cookie');
$url = "http://icas.jnu.edu.cn/cas/login";
$post_fields = 'lt=LT-AlwaysValidTicket&loginErrCnt=0&service=http%3A%2F%2Fi.jnu.edu.cn%2Fdcp%2Findex.jsp&encodedService=http%253a%252f%252fi.jnu.edu.cn%252fdcp%252Findex.jsp&userNameType=cardID&username=188861&password1=053153&password=d9276d14dd857979c4db516cb5442e83&button1=';

$ch = curl_init($url);
curl_setopt($ch, CURLOPT_HEADER, 0); //头部
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_POST, true);
curl_setopt($ch, CURLOPT_COOKIEJAR, $cookie_file);
curl_setopt($ch, CURLOPT_POSTFIELDS, $post_fields);

$cookie_file;
echo $output = curl_exec($ch);
curl_close($ch);


//读取cookie
$handle = fopen($cookie_file, "r");  
$contents = "";  
while (!feof($handle)) {  
 $contents .= fread($handle, 8192);  
}  
fclose($handle);  
echo $contents;

function getContentBySnoopy($url, $cookieStr){
	$snoopy = new Snoopy();
	$snoopy->host = "weibo.com";
	$snoopy->agent = "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36 QIHU 360SE";
	$snoopy->referer = '';
	$items = explode(";", $cookieStr);
	foreach ($items as $item) {
		$kv = explode("=", $item);
		$snoopy->cookies[trim($kv[0])] = urldecode(trim($kv[1])) ;
	}
	$snoopy->fetch($url);
	return $snoopy->results;
}

echo getContentBySnoopy(URL, $contents)

?>