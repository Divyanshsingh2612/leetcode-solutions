# Write your MySQL query statement below
select t.request_at as day,
round(
    sum(case
    when t.status in ('cancelled_by_driver','cancelled_by_client')
    then 1 else 0
    end)/count(*),
    2
) as 'cancellation rate'
from trips t
join users c
on t.client_id = c.users_id
join users d
on t.driver_id = d.users_id
where c.banned = 'No'
and d.banned = 'No'
and t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at
order by t.request_at;