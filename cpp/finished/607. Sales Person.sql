select s.name
from salesperson s
    left join (
        select o.sales_id, count(c.name) as red_cnt
        from orders o
            left join (
                select com_id, name
                from company
                where name = "RED"
            ) as c on o.com_id = c.com_id
        group by o.sales_id
    ) as red on s.sales_id = red.sales_id
where red.red_cnt = 0
    or red.red_cnt is null