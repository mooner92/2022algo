-- 매장유형 테이블
CREATE TABLE 매장유형 (
    매장유형ID INT PRIMARY KEY,
    매장유형명 VARCHAR(50)
);

-- 매장 테이블
CREATE TABLE 매장 (
    매장ID INT PRIMARY KEY,
    매장명 VARCHAR(50),
    지역 VARCHAR(50),
    매장유형ID INT,
    FOREIGN KEY (매장유형ID) REFERENCES 매장유형(매장유형ID)
);

-- 재료 테이블
CREATE TABLE 재료 (
    재료ID INT PRIMARY KEY,
    재료명 VARCHAR(50)
);

-- 메뉴 테이블
CREATE TABLE 메뉴 (
    메뉴ID INT PRIMARY KEY,
    메뉴명 VARCHAR(50),
    가격 INT,
    재료ID INT,
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 고객 테이블
CREATE TABLE 고객 (
    고객ID INT PRIMARY KEY,
    고객명 VARCHAR(50),
    연락처 VARCHAR(50)
);

-- 주문 테이블
CREATE TABLE 주문 (
    주문ID INT PRIMARY KEY,
    매장ID INT,
    고객ID INT,
    주문일자 DATE,
    FOREIGN KEY (매장ID) REFERENCES 매장(매장ID),
    FOREIGN KEY (고객ID) REFERENCES 고객(고객ID)
);

-- 주문상세 테이블
CREATE TABLE 주문상세 (
    주문상세ID INT PRIMARY KEY,
    주문ID INT,
    메뉴ID INT,
    수량 INT,
    FOREIGN KEY (주문ID) REFERENCES 주문(주문ID),
    FOREIGN KEY (메뉴ID) REFERENCES 메뉴(메뉴ID)
);

-- 원두 테이블
CREATE TABLE 원두 (
    원두ID INT PRIMARY KEY,
    원두명 VARCHAR(50),
    재료ID INT,
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 우유 테이블
CREATE TABLE 우유 (
    우유ID INT PRIMARY KEY,
    우유명 VARCHAR(50),
    재료ID INT,
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 시럽 테이블
CREATE TABLE 시럽 (
    시럽ID INT PRIMARY KEY,
    시럽명 VARCHAR(50),
    재료ID INT,
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 매장-메뉴 테이블
CREATE TABLE 매장_메뉴 (
    매장ID INT,
    메뉴ID INT,
    PRIMARY KEY (매장ID, 메뉴ID),
    FOREIGN KEY (매장ID) REFERENCES 매장(매장ID),
    FOREIGN KEY (메뉴ID) REFERENCES 메뉴(메뉴ID)
);

-- 매장-고객 테이블
CREATE TABLE 매장_고객 (
    매장ID INT,
    고객ID INT,
    PRIMARY KEY (매장ID, 고객ID),
    FOREIGN KEY (매장ID) REFERENCES 매장(매장ID),
    FOREIGN KEY (고객ID) REFERENCES 고객(고객ID)
);

-- 주문-주문상세 테이블
CREATE TABLE 주문_주문상세 (
    주문ID INT,
    주문상세ID INT,
    PRIMARY KEY (주문ID, 주문상세ID),
    FOREIGN KEY (주문ID) REFERENCES 주문(주문ID),
    FOREIGN KEY (주문상세ID) REFERENCES 주문상세(주문상세ID)
);

-- 메뉴-주문상세 테이블
CREATE TABLE 메뉴_주문상세 (
    메뉴ID INT,
    주문상세ID INT,
    PRIMARY KEY (메뉴ID, 주문상세ID),
    FOREIGN KEY (메뉴ID) REFERENCES 메뉴(메뉴ID),
    FOREIGN KEY (주문상세ID) REFERENCES 주문상세(주문상세ID)
);

-- 원두-재료 테이블
CREATE TABLE 원두_재료 (
    원두ID INT,
    재료ID INT,
    PRIMARY KEY (원두ID, 재료ID),
    FOREIGN KEY (원두ID) REFERENCES 원두(원두ID),
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 우유-재료 테이블
CREATE TABLE 우유_재료 (
    우유ID INT,
    재료ID INT,
    PRIMARY KEY (우유ID, 재료ID),
    FOREIGN KEY (우유ID) REFERENCES 우유(우유ID),
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 시럽-재료 테이블
CREATE TABLE 시럽_재료 (
    시럽ID INT,
    재료ID INT,
    PRIMARY KEY (시럽ID, 재료ID),
    FOREIGN KEY (시럽ID) REFERENCES 시럽(시럽ID),
    FOREIGN KEY (재료ID) REFERENCES 재료(재료ID)
);

-- 매장유형 테이블 INSERT
INSERT INTO 매장유형 VALUES (
    1,
    '일반'
),
(
    2,
    '리저브'
),
(
    3,
    '드라이브스루'
),
(
    4,
    '별다방'
) (
    5,
    '커뮤니티스토어'
);

-- 매장 테이블에 데이터 추가
INSERT INTO 매장 (
    매장ID,
    매장명,
    지역,
    매장유형ID
) VALUES (
    1,
    '스타벅스 서울점',
    '서울',
    1
),
(
    2,
    '스타벅스 부산점',
    '부산',
    2
),
(
    3,
    '스타벅스 대전점',
    '대전',
    3
),
(
    4,
    '스타벅스 인천점',
    '인천',
    4
),
(
    5,
    '스타벅스 광주점',
    '광주',
    5
),
(
    6,
    '스타벅스 대구점',
    '대구',
    1
),
(
    7,
    '스타벅스 울산점',
    '울산',
    2
),
(
    8,
    '스타벅스 경기점',
    '경기',
    3
),
(
    9,
    '스타벅스 강원점',
    '강원',
    4
),
(
    10,
    '스타벅스 충청점',
    '충청',
    5
);

-- 재료 테이블에 데이터 추가
INSERT INTO 재료 (
    재료ID,
    재료명
) VALUES (
    1,
    '밀가루'
),
(
    2,
    '설탕'
),
(
    3,
    '우유'
),
(
    4,
    '커피'
),
(
    5,
    '얼음'
),
(
    6,
    '차'
),
(
    7,
    '초콜릿'
),
(
    8,
    '계란'
),
(
    9,
    '소금'
),
(
    10,
    '버터'
);

-- 메뉴 테이블에 데이터 추가
INSERT INTO 메뉴 (
    메뉴ID,
    메뉴명,
    가격,
    재료ID
) VALUES (
    1,
    '아메리카노',
    3000,
    4
),
(
    2,
    '카페라떼',
    3500,
    4
),
(
    3,
    '카푸치노',
    3500,
    4
),
(
    4,
    '에스프레소',
    2500,
    4
),
(
    5,
    '아이스티',
    4000,
    6
),
(
    6,
    '프라푸치노',
    3500,
    7
),
(
    7,
    '몽블랑',
    2000,
    1
),
(
    8,
    '사과파이',
    2500,
    1
),
(
    9,
    '크림빵',
    2000,
    1
),
(
    10,
    '도넛',
    1500,
    1
);

-- 고객 테이블에 데이터 추가
INSERT INTO 고객 (
    고객ID,
    고객명,
    연락처
) VALUES (
    1,
    '홍길동',
    '010-1234-5678'
),
(
    2,
    '김철수',
    '010-9876-5432'
),
(
    3,
    '이영희',
    '010-5678-1234'
),
(
    4,
    '박민수',
    '010-2345-6789'
),
(
    5,
    '정미경',
    '010-8765-4321'
),
(
    6,
    '최재영',
    '010-3456-7890'
),
(
    7,
    '손지호',
    '010-6543-2109'
),
(
    8,
    '김지영',
    '010-7890-3456'
),
(
    9,
    '이승우',
    '010-4321-8765'
),
(
    10,
    '박현주',
    '010-9012-3456'
);

-- 주문 테이블에 데이터 추가
INSERT INTO 주문 (
    주문ID,
    매장ID,
    고객ID,
    주문일자
) VALUES (
    1,
    1,
    1,
    '2023-07-10'
),
(
    2,
    2,
    2,
    '2023-07-10'
),
(
    3,
    3,
    3,
    '2023-07-10'
),
(
    4,
    4,
    4,
    '2023-07-10'
),
(
    5,
    5,
    5,
    '2023-07-10'
),
(
    6,
    6,
    6,
    '2023-07-10'
),
(
    7,
    7,
    7,
    '2023-07-10'
),
(
    8,
    8,
    8,
    '2023-07-10'
),
(
    9,
    9,
    9,
    '2023-07-10'
),
(
    10,
    10,
    10,
    '2023-07-10'
);

-- 주문상세 테이블에 데이터 추가
INSERT INTO 주문상세 (
    주문상세ID,
    주문ID,
    메뉴ID,
    수량
) VALUES (
    1,
    1,
    1,
    2
),
(
    2,
    2,
    2,
    1
),
(
    3,
    3,
    3,
    3
),
(
    4,
    4,
    4,
    2
),
(
    5,
    5,
    5,
    1
),
(
    6,
    6,
    6,
    3
),
(
    7,
    7,
    7,
    2
),
(
    8,
    8,
    8,
    1
),
(
    9,
    9,
    9,
    3
),
(
    10,
    10,
    10,
    2
);

-- 원두 테이블에 데이터 추가
INSERT INTO 원두 (
    원두ID,
    원두명,
    재료ID
) VALUES (
    1,
    '브라질 원두',
    4
),
(
    2,
    '콜롬비아 원두',
    4
),
(
    3,
    '에티오피아 원두',
    4
),
(
    4,
    '자메이카 원두',
    4
),
(
    5,
    '하와이 원두',
    4
),
(
    6,
    '과테말라 원두',
    4
),
(
    7,
    '케냐 원두',
    4
),
(
    8,
    '인도 원두',
    4
),
(
    9,
    '멕시코 원두',
    4
),
(
    10,
    '탄자니아 원두',
    4
);

-- 우유 테이블에 데이터 추가
INSERT INTO 우유 (
    우유ID,
    우유명,
    재료ID
) VALUES (
    1,
    '생우유',
    3
),
(
    2,
    '저지방 우유',
    3
),
(
    3,
    '무지방 우유',
    3
),
(
    4,
    '두유',
    3
),
(
    5,
    '오트(귀리) 우유',
    3
);

INSERT INTO 시럽 (
    시럽ID,
    시럽명,
    재료ID
) VALUES (
    11,
    '바닐라 시럽',
    2
),
(
    12,
    '카라멜 시럽',
    2
),
(
    13,
    '헤이즐넛 시럽',
    2
),
(
    14,
    '모카 시럽',
    2
),
(
    15,
    '민트 시럽',
    2
),
(
    16,
    '초콜릿 시럽',
    2
),
(
    17,
    '딸기 시럽',
    2
);

-- 매장-메뉴 테이블에 데이터 추가
INSERT INTO 매장_메뉴 (
    매장ID,
    메뉴ID
) VALUES (
    1,
    1
),
(
    2,
    2
),
(
    3,
    3
),
(
    4,
    4
),
(
    5,
    5
),
(
    6,
    6
),
(
    7,
    7
),
(
    8,
    8
),
(
    9,
    9
),
(
    10,
    10
);

-- 매장-고객 테이블에 데이터 추가
INSERT INTO 매장_고객 (
    매장ID,
    고객ID
) VALUES (
    1,
    1
),
(
    2,
    2
),
(
    3,
    3
),
(
    4,
    4
),
(
    5,
    5
),
(
    6,
    6
),
(
    7,
    7
),
(
    8,
    8
),
(
    9,
    9
),
(
    10,
    10
);

-- 주문-주문상세 테이블에 데이터 추가
INSERT INTO 주문_주문상세 (
    주문ID,
    주문상세ID
) VALUES (
    1,
    1
),
(
    2,
    2
),
(
    3,
    3
),
(
    4,
    4
),
(
    5,
    5
),
(
    6,
    6
),
(
    7,
    7
),
(
    8,
    8
),
(
    9,
    9
),
(
    (계속) ```SQL 10,
    10
);

-- 메뉴-주문상세 테이블에 데이터 추가
INSERT INTO 메뉴_주문상세 (
    메뉴ID,
    주문상세ID
) VALUES (
    1,
    1
),
(
    2,
    2
),
(
    3,
    3
),
(
    4,
    4
),
(
    5,
    5
),
(
    6,
    6
),
(
    7,
    7
),
(
    8,
    8
),
(
    9,
    9
),
(
    10,
    10
);

-- 원두-재료 테이블에 데이터 추가
INSERT INTO 원두_재료 (
    원두ID,
    재료ID
) VALUES (
    1,
    1
),
(
    2,
    2
),
(
    3,
    3
),
(
    4,
    4
),
(
    5,
    5
),
(
    6,
    6
),
(
    7,
    7
),
(
    8,
    8
),
(
    9,
    9
),
(
    10,
    10
);

-- 우유-재료 테이블에 데이터 추가
INSERT INTO 우유_재료 (
    우유ID,
    재료ID
) VALUES (
    1,
    1
),
(
    2,
    2
),
(
    3,
    3
),
(
    4,
    4
),
(
    5,
    5
),
(
    1,
    6
),
(
    1,
    7
),
(
    3,
    8
),
(
    1,
    9
),
(
    2,
    10
);

-- 시럽-재료 테이블에 데이터 추가
INSERT INTO 시럽_재료 (
    시럽ID,
    재료ID
) VALUES (
    11,
    1
),
(
    12,
    2
),
(
    13,
    3
),
(
    14,
    4
),
(
    15,
    5
),
(
    16,
    6
),
(
    11,
    7
),
(
    17,
    8
),
(
    14,
    9
),
(
    16,
    10
);