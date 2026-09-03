# Write your MySQL query statement below
SELECT Project.project_id, AVG(Employee.experience_years) AS average_years
FROM Project
JOIN Employee
ON Project.employee_id = Employee.employee_id
GROUP BY Project.project_id;