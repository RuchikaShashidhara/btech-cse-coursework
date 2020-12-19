-- Microsoft SQL Script that retrieves the GPA of a particular Student

USE UNIVERSITY;

DROP VIEW IF EXISTS GRADES;

GO

-- Creating a View GRADES that contains the Student Name and His/Her Grades in numbers(0-4) for each Course
CREATE VIEW GRADES(STnum, GRnum) AS
SELECT S.Name,
       CASE WHEN GR.Grade = 'A' THEN 4.0
			WHEN GR.Grade = 'B' THEN 3.0
			WHEN GR.Grade = 'C' THEN 2.0
			WHEN GR.Grade = 'D' THEN 1.0
			ELSE 0.0
	   END
FROM dbo.STUDENT AS S, dbo.GRADE_REPORT AS GR
WHERE S.Student_number = GR.Student_number;

GO

-- Creating a Table FINALGPA with column names Student_Name and Student_GPA
DROP TABLE IF EXISTS FINALGPA;
CREATE TABLE FINALGPA (
Student_Name VARCHAR(30) NOT NULL,
Student_GPA FLOAT(10) NOT NULL
PRIMARY KEY (Student_Name)
);

-- Inserting the final GPA for each Student_Name (Student)
INSERT INTO FINALGPA
SELECT STnum, CAST(AVG(GRnum) AS DECIMAL(10, 2)) AS GPA
FROM dbo.GRADES
GROUP BY STnum ;

SELECT * FROM FINALGPA;

