# Write your MySQL query statement below
# select st.student_id,st.student_name,s.subject_name, count(e.subject_name) as attended_exams
# from (Students as st join Examinations as e
# on st.student_id = e.student_id) Join Subjects as s 
# on s.subject_name = e.subject_name
# group by st.student_name
# order by st.student_id and s.subject_name;

# SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams
# FROM Students s
# CROSS JOIN Subjects sub
# LEFT JOIN Examinations e ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
# GROUP BY s.student_id, s.student_name, sub.subject_name
# ORDER BY s.student_id, sub.subject_name;

select s.student_id, s.student_name, sub.subject_name, count(e.student_id) as attended_exams
from Students s cross join Subjects sub
left join Examinations e 
on s.student_id = e.student_id and sub.subject_name = e.subject_name
group by s.student_id, s.student_name, sub.subject_name
order by s.student_id, sub.subject_name;