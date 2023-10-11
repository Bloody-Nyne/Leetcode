# Write your MySQL query statement below
select m.name from 
employee as e
inner join
employee as m
on m.id = e.managerId
group by e.managerId
having count(e.id) >= 5;