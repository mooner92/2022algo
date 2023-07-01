--------------------SELECT 7문제--------------------

--동물의 아이디와 이름
--https://school.programmers.co.kr/learn/courses/30/lessons/59403
SELECT
    ANIMAL_ID,
    NAME
FROM
    ANIMAL_INS
ORDER BY
    ANIMAL_ID;

--여러 기준으로 정렬하기
--https://school.programmers.co.kr/learn/courses/30/lessons/59404
SELECT
    ANIMAL_ID,
    NAME,
    DATETIME
FROM
    ANIMAL_INS
ORDER BY
    NAME,
    DATETIME DESC;

--어린 동물 찾기
--https://school.programmers.co.kr/learn/courses/30/lessons/59037#fn1
SELECT
    ANIMAL_ID,
    NAME
FROM
    ANIMAL_INS
WHERE
    INTAKE_CONDITION != 'Aged'
ORDER BY
    ANIMAL_ID;

--아픈 동물 찾기
--https://school.programmers.co.kr/learn/courses/30/lessons/59036
SELECT
    ANIMAL_ID,
    NAME
FROM
    ANIMAL_INS
WHERE
    INTAKE_CONDITION = 'Sick'
ORDER BY
    ANIMAL_ID;

--역순 정렬하기
--https://school.programmers.co.kr/learn/courses/30/lessons/59035
SELECT
    NAME,
    DATETIME
FROM
    ANIMAL_INS
ORDER BY
    ANIMAL_ID DESC;

--모든 레코드 조회하기
--https://school.programmers.co.kr/learn/courses/30/lessons/59034
SELECT
    *
FROM
    ANIMAL_INS
ORDER BY
    ANIMAL_ID ASC;

--인기있는 아이스크림
--https://school.programmers.co.kr/learn/courses/30/lessons/133024
SELECT
    FLAVOR
FROM
    FIRST_HALF
ORDER BY
    TOTAL_ORDER DESC,
    SHIPMENT_ID ASC;

--------------------SUM,MAX,MIN 4문제--------------------

--가장 비싼 상품 구하기
--https://school.programmers.co.kr/learn/courses/30/lessons/131697
SELECT
    MAX(PRICE)
FROM
    PRODUCT
 --가격이 제일 비싼 식품의 정보 출력하기
 --SELECT PRODUCT_ID, PRODUCT_NAME, PRODUCT_CD, CATEGORY, PRICE
FROM
    FOOD_PRODUCT
WHERE
    PRICE = (
        SELECT
            MAX(PRICE)
        FROM
            FOOD_PRODUCT
    );

--최댓값 구하기
--https://school.programmers.co.kr/learn/courses/30/lessons/59415
SELECT
    MAX(DATETIME)
FROM
    ANIMAL_INS;

--------------------GROUP BY 4문제--------------------

--동명 동물 수 찾기
--https://school.programmers.co.kr/learn/courses/30/lessons/59041
SELECT
    NAME,
    COUNT(NAME) AS 사용횟수
FROM
    ANIMAL_INS
WHERE
    NAME IS NOT NULL
GROUP BY
    NAME
HAVING
    COUNT(NAME) >= 2
ORDER BY
    NAME;

--진료과별 총 예약 횟수 출력하기
--https://school.programmers.co.kr/learn/courses/30/lessons/132202
SELECT
    MCDP_CD AS '진료과 코드',
    COUNT(*) AS '5월예약건수'
FROM
    APPOINTMENT
WHERE
    APNT_YMD >= '2022-05-01'
    AND APNT_YMD < '2022-06-01'
GROUP BY
    MCDP_CD
ORDER BY
    '5월예약건수' ASC,
    '진료과 코드' ASC;

--성분으로 구분한 아이스크림 총 주문량
--https://school.programmers.co.kr/learn/courses/30/lessons/133026
SELECT
    I.INGREDIENT_TYPE,
    SUM(F.TOTAL_ORDER) AS TOTAL_ORDER
FROM
    ICECREAM_INFO I
    INNER JOIN FIRST_HALF F
    ON I.FLAVOR = F.FLAVOR
GROUP BY
    I.INGREDIENT_TYPE
ORDER BY
    TOTAL_ORDER ASC;

--카테고리 별 도서 판매량 집계하기
--https://school.programmers.co.kr/learn/courses/30/lessons/144855
SELECT
    BOOK.CATEGORY         AS CATEGORY,
    SUM(BOOK_SALES.SALES) AS TOTAL_SALES
FROM
    BOOK
    JOIN BOOK_SALES
    ON BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
WHERE
    EXTRACT(YEAR FROM BOOK_SALES.SALES_DATE) = 2022
    AND EXTRACT(MONTH FROM BOOK_SALES.SALES_DATE) = 1
GROUP BY
    BOOK.CATEGORY
ORDER BY
    CATEGORY ASC;