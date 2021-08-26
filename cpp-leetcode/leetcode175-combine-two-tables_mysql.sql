# Write your MySQL query statement below
SELECT tb1.FirstName, tb1.LastName, tb2.City, tb2.State
FROM Person as tb1 
left join Address as tb2
on tb1.PersonId = tb2.PersonId;