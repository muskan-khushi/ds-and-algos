# Exchange Seats

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Table: `Seat`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
The ID sequence always starts from 1 and increments continuously.

```

 

Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.

Return the result table ordered by `id`  **in ascending order**.

The result format is in the following example.

 

 **Example 1:** 

```
Input: 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
Output: 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
Explanation: 
Note that if the number of students is odd, there is no need to change the last one's seat.

```

## Solution

**Language:** SQL  
**Runtime:** 470 ms (beats 15.16%)  
**Memory:** 0B (beats 100.00%)  
**Submitted:** 2026-09-08T09:27:56.079Z  

```sql
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


```

---

[View on LeetCode](https://leetcode.com/problems/exchange-seats/)