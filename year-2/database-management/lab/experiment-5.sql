-- A view is a virtual table. It's essentially a window into your table.
-- Sytax for creating a view is: CREATE VIEW emp-view AS SELECT eid, name, sal FROM emp

SHOW DATABASES;

USE adbms_lab;

CREATE TABLE EMPLOYEES (
	Employee_id CHARACTER(10) PRIMARY KEY,
    First_Name CHARACTER(10),
    Last_Name CHARACTER(10),
    DOB DATE,
    Salary DECIMAL(25),
    Department_id CHARACTER(10)
);

SELECT * FROM EMPLOYEES;

CREATE VIEW emp_view AS SELECT Employee_id, Last_Name, Salary, Department_id FROM EMPLOYEES;

SELECT * FROM emp_view;

INSERT INTO emp_view(Employee_id, Last_Name, Salary, Department_id) VALUES
('1000', 'A', 2210, "D1"),
('1001', 'B', 1250, "D2"),
('1002', 'C', 1760, "D3"),
('1003', 'D', 4590, "D4"),
('1004', 'E', 3670, "D5");

DROP TABLE EMPLOYEES;
DELETE FROM EMPLOYEES;

DROP VIEW emp_view;