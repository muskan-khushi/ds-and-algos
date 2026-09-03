# Write your MySQL query statement below
SELECT contest_id, ROUND(
    COUNT(user_id)*100/(SELECT COUNT(*) FROM Users), 2
) AS Percentage
FROM Register
GROUP BY contest_id
ORDER BY Percentage DESC, contest_id ASC;