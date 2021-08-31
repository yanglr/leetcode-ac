# Write your MySQL query statement below
SELECT tb1.name, tb1.population, tb1.area
FROM World as tb1
WHERE tb1.area >= 3000000 or tb1.population >= 25000000;