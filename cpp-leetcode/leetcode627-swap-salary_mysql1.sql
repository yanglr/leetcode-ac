# Write your MySQL query statement below
UPDATE salary
set 
    sex = CASE 
    when sex= 'm' then 'f'
    else 'm' 
    end;