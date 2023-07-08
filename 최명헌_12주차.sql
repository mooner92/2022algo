--1. 조건에 맞는 도서와 저자 리스트 출력하기
--https://school.programmers.co.kr/learn/courses/30/lessons/144854
SELECT
    B.BOOK_ID,
    A.AUTHOR_NAME,
    DATE_FORMAT(B.PUBLISHED_DATE,
    '%Y-%m-%d') AS PUBLISHED_DATE
FROM
    BOOK   B
    JOIN AUTHOR A
    ON B.AUTHOR_ID = A.AUTHOR_ID
WHERE
    B.CATEGORY = '경제'
ORDER BY
    PUBLISHED_DATE ASC;

--2. 있었는데요 없었습니다
--https://school.programmers.co.kr/learn/courses/30/lessons/59043
SELECT
    AI.ANIMAL_ID,
    AI.NAME
FROM
    ANIMAL_INS  AI
    JOIN ANIMAL_OUTS AO
    ON AI.ANIMAL_ID = AO.ANIMAL_ID
WHERE
    AI.DATETIME > AO.DATETIME
ORDER BY
    AI.DATETIME ASC;

--3. 없어진 기록 찾기
--https://school.programmers.co.kr/learn/courses/30/lessons/59042
SELECT
    AO.ANIMAL_ID,
    AO.NAME
FROM
    ANIMAL_OUTS AO
    LEFT JOIN ANIMAL_INS AI
    ON AO.ANIMAL_ID = AI.ANIMAL_ID
WHERE
    AI.ANIMAL_ID IS NULL
ORDER BY
    AO.ANIMAL_ID;

--4. 상품 별 오프라인 매출 구하기
--https://school.programmers.co.kr/learn/courses/30/lessons/131533
SELECT
    P.PRODUCT_CODE,
    SUM(P.PRICE * O.SALES_AMOUNT) AS SALES
FROM
    PRODUCT      P
    JOIN OFFLINE_SALE O
    ON P.PRODUCT_ID = O.PRODUCT_ID
GROUP BY
    P.PRODUCT_CODE
ORDER BY
    SALES DESC, P.PRODUCT_CODE ASC;

--5. 오랜 기간 보호한 동물(1)
--https://school.programmers.co.kr/learn/courses/30/lessons/59044
SELECT
    A.NAME,
    A.DATETIME
FROM
    ANIMAL_INS A
    LEFT JOIN ANIMAL_OUTS O
    ON A.ANIMAL_ID = O.ANIMAL_ID
WHERE
    O.ANIMAL_ID IS NULL
ORDER BY
    A.DATETIME LIMIT 3;

---