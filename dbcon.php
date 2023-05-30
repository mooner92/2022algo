<?php

// MySQL 데이터베이스 연결 설정
$servername = "sudosoft-1.cpf9r06qfgdc.us-east-2.rds.amazonaws.com"; // MySQL 서버 주소
$username = "user"; // MySQL 사용자명
$password = "chocho0804"; // MySQL 비밀번호
$dbname = "chatting_log"; // 사용할 데이터베이스명

// POST 요청으로부터 데이터 가져오기
$data1 = $_POST['data1']; // 채팅
$data2 = $_POST['data2']; // 시간

// MySQL 데이터베이스 연결
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("MySQL 연결 실패: " . $conn->connect_error);
}

// 데이터베이스에 데이터 삽입
$sql = "INSERT INTO chatting_2 (chat, times) VALUES ('$data1', '$data2')"; // 삽입할 데이터의 열(column1_name, column2_name)과 테이블명을 수정해야 합니다.
if ($conn->query($sql) === TRUE) {
    echo "데이터가 성공적으로 삽입되었습니다.";
} else {
    echo "데이터 삽입 오류: " . $conn->error;
}

// MySQL 연결 종료
$conn->close();

?>
