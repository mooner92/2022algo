/*(1) HR 부서에서 예산 편성 문제로 급여 정보 보고서를 작성하려고 한다. 사원정보
(EMPLOYEES) 테이블에서 급여가 $8,000~$12,000 범위 이외인 사람의 성과 이름(Name으로
별칭) 및 급여를 급여가 큰 순서로 출력하시오.*/
SELECT
    LAST_NAME  AS 성,
    FIRST_NAME AS 이름,
    SALARY     AS 급여
FROM
    EMPLOYEES
WHERE
    SALARY NOT BETWEEN 8000
    AND 12000
ORDER BY
    SALARY DESC;

/*(2) 현재 날짜 타입을 날짜 함수를 통해 확인하고, 2007년 04월 20일부터 2008년 09월 20
일 사이에 고용된 사원들의 성과 이름(Name으로 별칭), 사원번호, 고용일자를 출력하시오. 단, 입사일이 빠른 순으로 정렬하시오.*/
SELECT
    LAST_NAME   AS 성,
    FIRST_NAME  AS 이름,
    EMPLOYEE_ID AS 사원번호,
    HIRE_DATE   AS 고용일자
FROM
    EMPLOYEES
WHERE
    HIRE_DATE BETWEEN TO_DATE('2007-04-20',
    'YYYY-MM-DD')
    AND TO_DATE('2008-09-20',
    'YYYY-MM-DD')
ORDER BY
    HIRE_DATE;

/*(3) 사원들의 업무별 전체 급여 평균이 $5,000보다 큰 경우를 조회하여 업무, 급여 평균을
출력하시오. 단, 업무에 사원(CLERK)이 포함된 경우는 제외하고 전체 급여 평균이 낮은 순서대로 출력하시오.*/
SELECT
    JOB_ID      AS 업무,
    AVG(SALARY) AS 급여평균
FROM
    EMPLOYEES
WHERE
    JOB_ID NOT LIKE 'CLERK'
GROUP BY
    JOB_ID
HAVING
    AVG(SALARY) > 5000
ORDER BY
    AVG(SALARY) ASC;

/*(4) HR 부서의 어떤 사원은 급여 정보를 조회하는 업무를 맡고 있다. 
Tucker(last_name) 사원보다 급여를 적게 받고 있는 사원의 성과 이름 (Name으로 별칭), 업무, 급여를 출력하시오.*/
SELECT
    LAST_NAME  AS 성,
    FIRST_NAME AS 이름,
    JOB_ID     AS 업무,
    SALARY     AS 급여
FROM
    EMPLOYEES
WHERE
    JOB_ID = (
        SELECT
            JOB_ID
        FROM
            EMPLOYEES
        WHERE
            LAST_NAME = 'TUCKER'
    )
    AND SALARY < (
        SELECT
            SALARY
        FROM
            EMPLOYEES
        WHERE
            LAST_NAME = 'TUCKER'
    );

/*(5) 부서별 급여 합계를 구하고, 그 결과를 가지고 다음과 같이 표현하시오*/
SELECT
    DEPARTMENT_ID AS 부서번호,
    SUM(SALARY)   AS 총급여,
    CASE
        WHEN SUM(SALARY) > 200000 THEN
            'EXCELLENT'
        WHEN SUM(SALARY) > 150000 THEN
            'GOOD'
        WHEN SUM(SALARY) > 100000 THEN
            'MEDIUM'
        ELSE
            'WELL'
    END           AS 합계표현
FROM
    EMPLOYEES
GROUP BY
    DEPARTMENT_ID;