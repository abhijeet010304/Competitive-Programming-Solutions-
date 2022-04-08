# Write your MySQL query statement below

SELECT A.id
FROM Weather A, Weather B
WHERE datediff(a.RecordDate,b.RecordDate)=1 and A.temperature>B.temperature;

