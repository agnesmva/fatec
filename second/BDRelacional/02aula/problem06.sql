SELECT LASTNAME, SALARY, COMM, HIREDATE
FROM EMPLOYEE
WHERE SALARY >=  20000 AND HIREDATE > '1979-12-31';


SELECT LASTNAME, SALARY, COMM, HIREDATE
FROM EMPLOYEE
WHERE SALARY >=  20000 AND HIREDATE >= '1980-01-01';

SELECT LASTNAME, SALARY, COMM, HIREDATE
FROM EMPLOYEE
WHERE SALARY >=  20000 AND YEAR(HIREDATE) >= '1980';