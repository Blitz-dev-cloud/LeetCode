# Write your MySQL query statement below
SELECT player_id, event_date AS first_login
FROM (
    SELECT
        p.*,
        DENSE_RANK() OVER(
            PARTITION BY player_id
            ORDER BY event_date ASC
        ) as rnk
    FROM Activity p
) x
WHERE rnk = 1;