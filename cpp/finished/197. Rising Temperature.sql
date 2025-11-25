select w2.id
from Weather w1
left join Weather w2
on date_sub(w2.recordDate, interval 1 day) = w1.recordDate
where w2.temperature > w1.temperature