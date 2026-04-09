----Q1
SELECT * FROM EMPLOYEES
WHERE Salary > (SELECT AVG(Salary) FROM EMPLOYEES);

----Q2
SELECT * FROM EMPLOYEES
WHERE Salary = (
    SELECT MIN(Salary) FROM EMPLOYEES
    WHERE Department_id = (
        SELECT Department_id FROM DEPARTMENTS
        WHERE Department_name = 'IT'
    )
);

----Q3
SELECT * FROM EMPLOYEES
WHERE Hire_date > ANY(
    SELECT Hire_date FROM EMPLOYEES
    WHERE Last_name = 'King'
);

----Q4
SELECT * FROM EMPLOYEES
WHERE Department_id IN (
    SELECT Department_id FROM DEPARTMENTS
    WHERE Location_id IN (
        SELECT Location_id FROM LOCATIONS
        WHERE City = 'Seattle'
    )
);

----Q5
SELECT * FROM EMPLOYEES
WHERE Salary > ALL (
    SELECT Salary FROM EMPLOYEES
    WHERE Department_id = 50
);

----Q6
SELECT * FROM EMPLOYEES
WHERE Salary > ANY (
    SELECT Salary FROM EMPLOYEES
    WHERE Department_id = 60
);

----Q7
SELECT * FROM EMPLOYEES
WHERE Department_id IN (
    SELECT Department_id FROM EMPLOYEES
    WHERE Salary > 10000
);

----Q8
SELECT * FROM EMPLOYEES e
WHERE Salary > (
    SELECT AVG(Salary) FROM EMPLOYEES
    WHERE Department_id = e.Department_id
);

----Q9
SELECT * FROM EMPLOYEES e
WHERE Salary = (
    SELECT MAX(Salary) FROM EMPLOYEES
    WHERE Department_id = e.Department_id
);

----Q10
SELECT Department_id FROM EMPLOYEES
GROUP BY Department_id HAVING COUNT(*) > (
    SELECT AVG(Cnt) FROM (
        SELECT COUNT(*) AS Cnt FROM EMPLOYEES
        GROUP BY Department_id
    )
);

----Q11
SELECT * FROM EMPLOYEES e
WHERE Salary > (
    SELECT AVG(Salary) FROM EMPLOYEES
    WHERE Job_id = e.Job_id
);

----Q12
SELECT * FROM EMPLOYEES
WHERE (Job_id, Salary) IN (
    SELECT Job_id, Salary FROM EMPLOYEES
    WHERE Last_name = 'Taylor'
);

----Q13
SELECT * FROM EMPLOYEES
WHERE (Department_id, Job_id) = (
    SELECT Department_id, Job_id FROM EMPLOYEES
    WHERE Last_name = 'Whalen'
);

----Q14
SELECT * FROM DEPARTMENTS d
WHERE EXISTS (
    SELECT 1 FROM EMPLOYEES e
    WHERE e.Department_id = d.Department_id
);

----Q15
SELECT * FROM DEPARTMENTS d
WHERE NOT EXISTS (
    SELECT 1 FROM EMPLOYEES e
    WHERE e.Department_id = d.Department_id
);

----Q16
SELECT * FROM EMPLOYEES
WHERE Employee_id IN (
    SELECT Employee_id FROM JOB_HISTORY
);

----Q17
SELECT * FROM EMPLOYEES
WHERE Employee_id NOT IN (
    SELECT Employee_id FROM JOB_HISTORY
);

----Q18
SELECT * FROM (
    SELECT * FROM EMPLOYEES
    ORDER BY Salary DESC
)
WHERE ROWNUM <= 3;

----Q19
SELECT * FROM (
    SELECT Department_id, AVG(Salary) AS Avg_sal FROM EMPLOYEES
    GROUP BY Department_id
)
WHERE Avg_sal > 8000;

----Q20 (Create the table first with exact colunm like Employee table but no data)
CREATE TABLE HIGH_PAID_EMPLOYEES AS
SELECT * FROM EMPLOYEES
WHERE 1 = 0;

INSERT INTO HIGH_PAID_EMPLOYEES
SELECT * FROM EMPLOYEES
WHERE Salary > (SELECT AVG(Salary) FROM EMPLOYEES);

SELECT * FROM HIGH_PAID_EMPLOYEES;

----Q21
UPDATE EMPLOYEES e
SET Salary = Salary * 1.10
WHERE Salary < (
    SELECT AVG(Salary) FROM EMPLOYEES
    WHERE Department_id = e.Department_id
);

----Q22
DELETE FROM EMPLOYEES
WHERE Department_id IN (
    SELECT Department_id FROM DEPARTMENTS
    WHERE Location_id IN (
        SELECT Location_id FROM LOCATIONS
        WHERE City = 'Toronto'
    )
);

DELETE FROM EMPLOYEES
WHERE Department_id IN (
    SELECT Department_id FROM DEPARTMENTS
    WHERE Location_id IN (
        SELECT Location_id FROM LOCATIONS
        WHERE City = 'Toronto'
    )
)
AND Employee_id NOT IN (
    SELECT Manager_id FROM DEPARTMENTS
    WHERE Manager_id IS NOT NULL
);

----Q23
---- Finally we select employees whose salary is greater than the average salary of these high-paying departments.
SELECT * FROM EMPLOYEES
WHERE Salary > (
    SELECT AVG(Salary) FROM EMPLOYEES       ---- Now finding emloyee who belong to department with greater then company avg salary
    WHERE Department_id IN (
        SELECT Department_id FROM (         ---- Find Department ID whose average salary is higher than the company average.
            SELECT Department_id, AVG(Salary) AS Avg_sal FROM EMPLOYEES
            GROUP BY Department_id          ---- Find Average Salary of Department and Grp them
        )
        WHERE Avg_sal > ( ---- Find overall average salary of the company.
            SELECT AVG(Salary) FROM EMPLOYEES
        )
    )
);

----Q24
SELECT * FROM EMPLOYEES ---- Finally we get employees who work in those department
WHERE Department_id IN (
    SELECT Department_id FROM DEPARTMENTS ---- Selectthe department ID of those location
    WHERE Location_id IN (
        SELECT Location_id FROM LOCATIONS ---- Select the Location Id of cities with greater Avg salary then company
        WHERE City IN (
            SELECT City FROM LOCATIONS l ---- Only pick cities where average salary is above company average.
            WHERE (
            ---- Calculates the average salary of employees in departments located in each city.
            SELECT AVG(Salary) FROM EMPLOYEES e
            JOIN DEPARTMENTS d ON e.Department_id = d.Department_id
            WHERE d.Location_id = l.Location_id
            ) > (SELECT AVG(Salary) FROM EMPLOYEES) ---- Find Company Total Average
        )
    )
);

----Q25
SELECT * FROM EMPLOYEES ---- Finally Select Employees whose Salary
is Greater than that Max salary
WHERE Salary > (
    SELECT MAX(Salary) FROM EMPLOYEES ---- Find the Max salry of the Employee from among these short listed Department
    WHERE Department_id IN (
        SELECT Department_id FROM EMPLOYEES             ---- Select Those Department whose Employee count is less then the Average
        GROUP BY Department_id HAVING COUNT(*) < (
            SELECT AVG(Cnt)FROM (                       ---- Calcualte the Average Number of Employee
                SELECT COUNT(*) AS Cnt FROM EMPLOYEES   ---- Find Total Number of Employees that exist in each Department
                GROUP BY Department_id
            )
        )
    )
);