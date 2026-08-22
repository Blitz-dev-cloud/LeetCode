# Write your MySQL query statement below
SELECT ROUND(SUM(i.tiv_2016), 2) AS tiv_2016
FROM Insurance i
WHERE i.tiv_2015 IN (SELECT i1.tiv_2015 FROM Insurance i1 WHERE i1.pid != i.pid)
AND (SELECT i3.lat, i3.lon FROM Insurance i3 WHERE i3.pid = i.pid) NOT IN (SELECT i2.lat, i2.lon FROM Insurance i2 WHERE i2.pid != i.pid);