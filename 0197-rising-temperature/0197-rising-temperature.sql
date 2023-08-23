# Write your MySQL query statement below


SELECT w2.id from Weather w1 CROSS JOIN Weather w2
ON w2.temperature > w1.temperature AND
datediff(w2.recordDate,w1.recordDate) = 1;