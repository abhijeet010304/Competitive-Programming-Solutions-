# Write your MySQL query statement below

Select name as Customers
from Customers where Customers.id not in (Select customerID from (Customers c INNER JOIN Orders o ON c.id = o.customerId));
