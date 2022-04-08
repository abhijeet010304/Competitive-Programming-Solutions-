# Write your MySQL query statement below

# select Person.firstName, Person.lastName, Address.city, Address.state
# from (Person LEFT JOIN Address ON Person.personId = Address.PersonId);


select p.firstName, p.lastName, a.city, a.state
from (Person p LEFT JOIN Address a ON p.personId = a.PersonId);