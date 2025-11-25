select x, y, z, case
        when x + y <= z then
            'No'
        when y + z <= x then
            'No'
        when x + z <= y then
            'No'
        else
            'Yes'
    end as triangle
from Triangle