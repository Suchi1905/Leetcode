# Write your MySQL query statement below
SELECT product_name,year,price
FROM Sales
RIGHT JOIN Product
ON Sales.product_id=Product.product_id
WHERE year IS NOT NULL;