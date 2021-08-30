# Write your MySQL query statement below
SELECT distinct tb1.Num as "ConsecutiveNums"
FROM Logs as tb1, Logs as tb2, Logs as tb3
WHERE tb1.Id + 1 = tb2.Id and tb2.Id + 1 = tb3.Id and tb1.Num = tb2.Num and tb2.Num = tb3.Num;