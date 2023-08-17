# Write your MySQL query statement below
SELECT p.product_name,s.year,s.price from Sales as s
LEFT JOIN Product as p ON p.product_id = s.product_id;