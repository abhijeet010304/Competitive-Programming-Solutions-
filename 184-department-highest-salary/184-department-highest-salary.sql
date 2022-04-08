# Write your MySQL query statement below

# select Department.name as Department, Employee.name as Employee, Employee.salary as Salary
# from (Employee INNER JOIN Department ON Employee.id=Department.id)
# where 

# Select b.name as Department, a.name as Employee, a.salary as Salary 
# from (Employee a INNER JOIN Department b ON a.id=b.id)
# where a.salary = 

select d.Name Department, e.Name Employee, Salary
from Department d join Employee e on d.Id=e.DepartmentId
where (Salary,d.id) in (select max(Salary),DepartmentId from Employee group by DepartmentId);