/* Write your PL/SQL query statement below */
SELECT 
    t1.id,
    CASE
        WHEN t1.p_id IS NULL THEN 'Root'
        WHEN t1.id IN (SELECT DISTINCT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree t1
ORDER BY t1.id;