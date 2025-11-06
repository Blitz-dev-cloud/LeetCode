/* Write your PL/SQL query statement below */
SELECT a.name AS Employee
FROM Employee a
JOIN Employee b
ON a.managerId = b.id
WHERE a.salary > b.salary;