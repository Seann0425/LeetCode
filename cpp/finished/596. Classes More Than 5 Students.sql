select class
from Courses c
group by class
having count(*) >= 5