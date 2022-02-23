select p1.id, p1.name, p1.host_id
from places p1
left join (
    select host_id, count(host_id) cnt
    from places
    group by host_id
) p2 on p1.host_id = p2.host_id
where p2.cnt > 1