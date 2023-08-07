# Write your MySQL query statement below
select name from customer where referee_id is NULL or referee_id !=2
#null values are not implicitly handled so explicitly checked it