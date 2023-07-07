--10주차 과제 ISNULL 3 문제 풀이하기
--mysql에선 ISNULL -> IFNULL

--경기도에 위치한 식품창고 목록 출력하기
--https://school.programmers.co.kr/learn/courses/30/lessons/131114
SELECT
    WAREHOUSE_ID,
    WAREHOUSE_NAME,
    ADDRESS,
    IFNULL(FREEZER_YN,
    'N') AS FREEZER_YN
FROM
    FOOD_WAREHOUSE
WHERE
    ADDRESS LIKE '%경기도%'
ORDER BY
    WAREHOUSE_ID;

--이름이 없는 동물의 아이디
--https://school.programmers.co.kr/learn/courses/30/lessons/59039
SELECT
    ANIMAL_ID
FROM
    ANIMAL_INS
WHERE
    IFNULL(NAME,
    '') = ''
ORDER BY
    ANIMAL_ID ASC;

--이름이 있는 동물의 아이디
--https://school.programmers.co.kr/learn/courses/30/lessons/59407
SELECT
    ANIMAL_ID
FROM
    ANIMAL_INS
WHERE
    IFNULL(NAME,
    '') != ''
ORDER BY
    ANIMAL_ID ASC;