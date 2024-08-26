/*
Problem 2
List last name, first name, and the department number for all employees. The listing
should be ordered by descending department numbers. Within the same
department, the last names should be sorted in descending order.
*/

select LASTNAME, FIRSTNME, WORKDEPT from EMPLOYEE
order by WORKDEPT desc, LASTNAME desc;