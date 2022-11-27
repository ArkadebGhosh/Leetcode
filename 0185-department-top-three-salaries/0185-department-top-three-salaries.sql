# Write your MySQL query statement below
SELECT D1.name AS Department, E1.name AS Employee, salary AS Salary 
FROM Employee E1 INNER JOIN Department D1 on E1.departmentId = D1.id
AND 3 > (SELECT COUNT(DISTINCT(salary)) FROM Employee E2 
         WHERE E2.departmentId = E1.departmentId
         AND E2.salary > E1.salary);