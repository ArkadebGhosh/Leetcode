CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT(salary) from Employee E1 WHERE N-1 = (SELECT COUNT(DISTINCT(SALARY)) FROM Employee E2 WHERE E2.salary > E1.salary)
  );
END