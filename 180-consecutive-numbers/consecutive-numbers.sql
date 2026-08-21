# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT
        l.num,
        LAG(num) OVER (ORDER BY id ASC) AS prev_num,
        LEAD(num) OVER (ORDER BY id ASC) AS next_num
    FROM Logs l
) t
WHERE num = prev_num
AND num = next_num;