--3.1 모든 도서의 이름과 가격을 검색하시오.
SELECT
    BOOKNAME,
    PRICE
FROM
    BOOK;

--3.2 모든 도서의 도서번호,도서이름,출판사,가격을 검색하시오.
SELECT
    BOOKID,
    BOOKNAME,
    PUBLISHER,
    PRICE
FROM
    BOOK;

--3.3 도서 테이블에 있는 모든 출판사를 검색하시오.
SELECT
    DISTINCT PUBLISHER
FROM
    BOOK;

--3.4 가격이 20,000원 미만인 도서를 검색하시오.
SELECT
    *
FROM
    BOOK
WHERE
    PRICE < 20000;

--3.5 가격이 10,000원 이상 20,000원 이하인 도서를 검색하시오.
SELECT
    *
FROM
    BOOK
WHERE
    PRICE BEETWEEN 10000
    AND 20000;

--