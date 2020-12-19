USE ZooPark;

/*LOSSLESS JOIN 1*/

SELECT * FROM customer;
SELECT * FROM ticket;
SELECT * FROM customer NATURAL JOIN ticket;

/*LOSSLESS JOIN 2*/

SELECT * FROM manages;
SELECT * FROM ticket;
SELECT * FROM employee;
SELECT * FROM animal NATURAL JOIN animal_kind;

/*TRIGGER BEFORE DELETE*/

DROP TABLE IF EXISTS Ticket_Archives;
CREATE TABLE Ticket_Archives (
    TAid INT PRIMARY KEY AUTO_INCREMENT,
    Tid VARCHAR(15), Price INT, Slot VARCHAR(15),
	Cid VARCHAR(15), Eid VARCHAR(15)
);

DROP TRIGGER IF EXISTS deleted_Tid_log
DELIMITER $$
CREATE TRIGGER deleted_Tid_log
    BEFORE DELETE
    ON ticket FOR EACH ROW
    BEGIN
        INSERT INTO Ticket_Archives(Tid, Price, Slot, Cid, Eid)
        VALUES(OLD.Tid, OLD.Price, OLD.Slot, OLD.Cid, 
               (SELECT Eid FROM MANAGES WHERE Tid = OLD.Tid));
    END$$

SELECT * FROM Ticket_Archives;
DELETE FROM TICKET WHERE Tid = 'T13';
DELETE FROM TICKET WHERE Tid = 'T16';
SELECT * FROM Ticket_Archives;

/*TRIGGER AFTER UPDATE*/

DROP TABLE IF EXISTS Growth_Archives;
CREATE TABLE Growth_Archives (
    ADGid INT PRIMARY KEY AUTO_INCREMENT,
    ADid VARCHAR(15), Age_new INT, Height_diff VARCHAR(15), Weight_diff VARCHAR(15)
);

DROP TRIGGER IF EXISTS updated_Animal_growth_log
DELIMITER $$
CREATE TRIGGER updated_Animal_growth_log
    AFTER UPDATE
    ON Animal_Detail FOR EACH ROW
    BEGIN
        IF NEW.Age > OLD.Age THEN
			INSERT INTO Growth_Archives(ADid, Age_new, Height_diff, Weight_diff)
			VALUES(OLD.Adid, NEW.Age, NEW.HEIGHT - OLD.Height, NEW.WEIGHT - OLD.Weight );
		END IF;
    END$$

SELECT * FROM Animal_Detail WHERE ADid = '60';
UPDATE ANIMAL_DETAIL  
SET Height = 18, Weight = 220, Age = 15
WHERE ADid = '60';
SELECT * FROM Animal_Detail WHERE ADid = '60';
SELECT * FROM growth_archives;

/*SQL Query 1*/

SELECT Zname, Location, Hours, Contact 
FROM ZOO 
WHERE Zid = ANY(SELECT Zid 
				FROM EMPLOYEE 
				WHERE Eid = ANY (SELECT Eid 
								 FROM MANAGES 
								 WHERE Tid='T14'));
/*SQL Query 2*/

SELECT * FROM EMPLOYEE;
SELECT CONCAT(EFname, ' ', ELname) as Emp_Name 
FROM EMPLOYEE 
WHERE Zid = ANY(SELECT Zid 
				FROM ZOO 
				WHERE Hours > 15);

/*SQL Query 3*/

SELECT * FROM TICKET;
SELECT CONCAT(CFname, ' ', CLname) as Customer_Full_Name, 
	   SUM(Price) as Total_Tickets_Price, 
	   COUNT(Cid) Total_Tickets 
FROM CUSTOMER NATURAL JOIN TICKET 
GROUP BY Cid;

/*SQL Query 4*/

SELECT SUM(Price) as Total_Tickets_Price 
FROM CUSTOMER NATURAL JOIN TICKET 
WHERE CONCAT(CFname, ' ', CLname) = 'Babu Rao'

/*SQL Query 5*/

SELECT animal_kind.AName, animal.Aid, animal.Feed_Time, animal.Cage_Number
FROM animal_kind
	LEFT OUTER JOIN animal ON animal_kind.AKid = animal.AKid 
	LEFT OUTER JOIN looks_after ON ANIMAL.Aid = looks_after.Aid
	LEFT OUTER JOIN employee ON employee.Eid = looks_after.Eid
WHERE CONCAT(employee.EFname, ' ', employee.ELname) = 'Phalak Jain'
ORDER BY animal_kind.AName;

/*SQL Query 6*/

SELECT ANIMAL_GUIDE.AGid, ANIMAL_GUIDE.Slot, ANIMAL_KIND.AName, ANIMAL_KIND.Population_Status, ANIMAL_GUIDE.Zoo_Introduction
FROM ANIMAL_KIND
	LEFT OUTER JOIN ZOO_CONTAINS ON ANIMAL_KIND.AKid = ZOO_CONTAINS.AKid
	LEFT OUTER JOIN ANIMAL_GUIDE ON ANIMAL_GUIDE.AGid = ZOO_CONTAINS.AGid
ORDER BY ANIMAL_GUIDE.AGid;


