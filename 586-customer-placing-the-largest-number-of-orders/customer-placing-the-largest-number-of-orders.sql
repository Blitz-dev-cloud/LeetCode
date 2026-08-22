# Write your MySQL query statement below
SELECT customer_number
FROM (
    SELECT
        o.*,
        DENSE_RANK() OVER (
            ORDER BY COUNT(o.order_number) DESC
        ) AS rnk
    FROM Orders o
    GROUP BY o.customer_number
) x
WHERE rnk = 1;