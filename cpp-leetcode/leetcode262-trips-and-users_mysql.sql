# Write your MySQL query statement below
SELECT tb1.Request_at as Day, Round(SUM(case when tb1.Status = 'completed' then 0 else 1 end)/count(*), 2) as 'Cancellation Rate'
From Trips as tb1
inner join Users as tb2
on tb1.Client_Id = tb2.Users_Id and tb2.Banned = "No"
inner join Users as tb3
on tb1.Driver_id = tb3.Users_Id and tb3.Banned = "No"
WHERE tb1.Request_at between "2013-10-01" and "2013-10-03"
GROUP BY tb1.Request_at
ORDER BY Day