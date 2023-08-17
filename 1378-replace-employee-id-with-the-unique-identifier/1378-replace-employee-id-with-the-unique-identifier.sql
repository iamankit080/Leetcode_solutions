# Write your MySQL query statement below
SELECT emp.unique_id, em.name FROM  Employees AS em  LEFT JOIN  EmployeeUNI as emp ON emp.id=em.id