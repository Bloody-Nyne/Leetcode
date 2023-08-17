# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.visit_id) as count_no_trans from Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id
where transaction_id is NULL
Group by customer_id;