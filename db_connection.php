<?php
$host = "sudosoft-1.cpf9r06qfgdc.us-east-2.rds.amazonaws.com"; // 데이터베이스 호스트 주소
$username = "user"; // 데이터베이스 사용자 이름
$password = "chocho0804"; // 데이터베이스 비밀번호
$dbname = "loc"; // 데이터베이스 이름

// MySQL 데이터베이스에 연결
$conn = mysqli_connect($host, $username, $password, $dbname);

// 연결 오류 확인
if (!$conn) {
    die("MySQL 연결 실패: " . mysqli_connect_error());
}
?>