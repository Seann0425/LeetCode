with cte as(
    select customer_number, count(*) as cnt
    from Orders o
    group by customer_number
),
max_cnt as (
    select max(cnt) as max_cnt
    from cte
)
select customer_number
from cte
where cnt = (select max_cnt from max_cnt);