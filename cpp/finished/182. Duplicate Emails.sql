select email as Email
from Person
group by email
having COUNT(email) > 1;