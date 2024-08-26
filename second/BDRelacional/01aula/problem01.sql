/*
Problema 1 
List employee number, last name, date of birth, and salary for all employees who make more than $30,000 a year. Sequence the result in descending order by salary.
*/

select EMPNO, LASTNAME, BIRTHDATE, SALARY from EMPLOYEE
where (SALARY > 30000)
order by SALARY desc;

