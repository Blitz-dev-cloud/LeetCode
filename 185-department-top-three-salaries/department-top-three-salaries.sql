# Write your MySQL query statement below
SELECT dname AS Department,
       ename AS Employee,
       salary AS Salary
FROM (
    SELECT
        d.name AS dname,
        e.name AS ename,
        e.salary AS salary,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS rnk
    FROM Employee e
    JOIN Department d
    ON e.departmentID = d.id
) x
WHERE rnk <= 3;