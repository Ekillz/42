<?php
session_start();
$table = "logs".$_SESSION['gameid'];
$uname = $_REQUEST['uname'];
$msg = $_REQUEST['msg'];
$pass = trim(file_get_contents("pass.txt"));
$link = mysql_connect("localhost:/nfs/zfs-student-3/users/2014/chaueur/mamp/mysql/tmp/mysql.sock", "root", "rootroot")
    or die("Impossible de se connecter : " . mysql_error());
if (!mysql_select_db('chatbox'))
{
	mysql_query("CREATE DATABASE chatbox");
	mysql_select_db('chatbox');
}
$query = "SHOW TABLES LIKE ".$table;
if (mysql_num_rows(mysql_query($query)) == 0)
{
	$query = "CREATE TABLE ".$table. "(id INT , username varchar(255), msg TEXT)";
	mysql_query($query);
}
$query =  "INSERT INTO ".$table. "(`username`, `msg`) VALUES ('$uname', '$msg')";
mysql_query($query);
$query = "SELECT * FROM ".$table." ORDER by id DESC";
$ress = mysql_query($query);
while ($extract = mysql_fetch_array($ress))
	echo "<font color='red'>".$extract['username'] ."</font>" . ": " . $extract['msg'] . "<br>";
?>
