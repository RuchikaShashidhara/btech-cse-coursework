-- Company Database Management System Queries

-- Select the Employee name, project name of the projects that the employee is working on

SELECT E.fname, E.lname, P.pname, W.hours
FROM COMPANY.dbo.EMPLOYEE E, 
	 Company.dbo.WORKS_ON W,
	 Company.dbo.Project P 
WHERE E.ssn = W.essn and W.pno = P.pnumber
ORDER BY 1,3,2;

-- Identify those projects that are managed by the department of an employee that he or she is not a part of
--It shows nothing as there are no relationship like the problem satement when we created the database

SELECT E.lname, E.fname, P.pname
FROM Company.dbo.EMPLOYEE E,
	 Company.dbo.PROJECT P
WHERE E.dno = P.dnum 
  and P.pnumber not in(
	SELECT P.pnumber
	FROM Company.dbo.WORKS_ON W
	WHERE W.essn = E.ssn
  );

--Identify those employees who don't have a dependent

SELECT E.lname, E.fname, E.ssn
FROM Company.dbo.EMPLOYEE E
WHERE not exists (
	SELECT DP.essn
	FROM Company.dbo.DEPENDENT DP
	WHERE DP.essn = E.ssn
);

-- Retrieve Employee last name, first name, salary, 'status'
-- 'status' : if salary > avg salary of the department, status = 'above_avg_salary'
--            if salary < avg salary of the department, status = 'below_avg_salary'
--            if salary = avg salary of the department, status = 'equal_to_avg_salary'

SELECT E2.lname, E2.fname, E2.salary,
CASE WHEN E2.Salary > AVG_SAL.AVG_PER_DEPT THEN 'Greater'
	 WHEN E2.Salary < AVG_SAL.AVG_PER_DEPT THEN 'Lesser'
	 WHEN E2.Salary = AVG_SAL.AVG_PER_DEPT THEN 'Equal_to'
END AS status
FROM Company.dbo.EMPLOYEE E2,
	(SELECT E.dno as dno, AVG(E.salary) as AVG_PER_DEPT
	FROM Company.dbo.EMPLOYEE E
	GROUP BY E.dno) AS AVG_SAL
WHERE E2.dno = AVG_SAL.dno

