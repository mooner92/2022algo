<?php
// 데이터베이스 연결 설정 파일
require_once 'db_connection.php';

// 데이터 조회 쿼리
$query = "SELECT * FROM locs";

// 데이터 조회 실행
$result = mysqli_query($conn, $query);

// 조회 결과를 배열로 저장
$locs = array();

if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $locs[] = $row;
    }
}

// JSON 형식으로 응답 반환
header('Content-Type: application/json');
echo json_encode($locs);

// 데이터베이스 연결 종료
mysqli_close($conn);
?>
