CREATE DATABASE FirstDB;

USE FirstDB;

CREATE TABLE Employee(
    EMPNO INT,
    ENAME VARCHAR(50),
    JOB VARCHAR(50),
    MANAGER_NO INT,
    SAL INT,
    COMMISSION INT
);

CREATE USER 'FirstUser'@'localhost';

GRANT ALL PRIVILEGES ON FirstDB.Employee TO 'FirstUser'@'localhost';

START TRANSACTION;

INSERT INTO Employee VALUES(1, 'John', 'Manager', 0, 10000, 1000);

INSERT INTO Employee VALUES(2, 'Jane', 'Manager', 0, 10000, 1000);

INSERT INTO Employee VALUES(3, 'Jack', 'Manager', 0, 10000, 1000);

SELECT * FROM Employee;

ROLLBACK;

SELECT * FROM Employee;

ALTER TABLE Employee ADD PRIMARY KEY(EMPNO);

ALTER TABLE Employee MODIFY EMPNO INT NOT NULL;

INSERT INTO Employee VALUES(NULL, 'John', 'Manager', 0, 10000, 1000);

INSERT INTO Employee VALUES(4, 'Jane', 'Manager', 0, 10000, 1000);

INSERT INTO Employee VALUES(5, 'Jack', 'Manager', 0, 10000, 1000);

SELECT * FROM Employee;

DROP TABLE Employee;

DROP USER 'FirstUser'@'localhost';