--9주차 과제 GROUP BY 4문제 풀이~

--조건에 맞는 사용자와 총 거래금액 조회하기
--https://school.programmers.co.kr/learn/courses/30/lessons/164668
SELECT
    U.USER_ID,
    U.NICKNAME,
    SUM(B.PRICE) AS TOTAL_SALES
FROM
    USED_GOODS_BOARD B
    JOIN USED_GOODS_USER U
    ON B.WRITER_ID = U.USER_ID
WHERE
    B.STATUS = 'DONE'
GROUP BY
    U.USER_ID, U.NICKNAME
HAVING
    SUM(B.PRICE) >= 700000
ORDER BY
    TOTAL_SALES ASC;

--자동차 종류 별 특정 옵션이 포함된 자동차 수 구하기
--https://school.programmers.co.kr/learn/courses/30/lessons/151137
SELECT
    CAR_TYPE,
    COUNT(*) AS CARS
FROM
    CAR_RENTAL_COMPANY_CAR
WHERE
    OPTIONS LIKE '%통풍시트%'
    OR OPTIONS LIKE '%열선시트%'
    OR OPTIONS LIKE '%가죽시트%'
GROUP BY
    CAR_TYPE
ORDER BY
    CAR_TYPE ASC;

--진료과별 총 예약 횟수 출력하기
--https://school.programmers.co.kr/learn/courses/30/lessons/132202
SELECT
    MCDP_CD  AS "진료과 코드",
    COUNT(*) AS "5월예약건수"
FROM
    APPOINTMENT
WHERE
    EXTRACT(YEAR FROM APNT_YMD) = 2022
    AND EXTRACT(MONTH FROM APNT_YMD) = 5
GROUP BY
    MCDP_CD
ORDER BY
    COUNT(*) ASC,
    MCDP_CD ASC;

--고양이와 개는 몇 마리 있을까
--https://school.programmers.co.kr/learn/courses/30/lessons/59040
SELECT
    ANIMAL_TYPE,
    COUNT(*) AS COUNT
FROM
    ANIMAL_INS
WHERE
    ANIMAL_TYPE IN ('Cat',
    'Dog')
GROUP BY
    ANIMAL_TYPE
ORDER BY
    FIELD(ANIMAL_TYPE,
    'Cat',
    'Dog');