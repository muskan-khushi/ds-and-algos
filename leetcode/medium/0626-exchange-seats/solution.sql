# Write your MySQL query statement below
SELECT s.id,
    CASE
        WHEN next.id IS NULL THEN s.student
        ELSE next.student
    END AS student
 FROM Seat s
 LEFT JOIN Seat next   
 ON next.id = CASE
                WHEN s.id%2 = 1 THEN s.id+1
                ELSE s.id-1
              END
ORDER  BY s.id;

