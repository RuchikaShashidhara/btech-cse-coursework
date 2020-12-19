/*ZOOLOGICAL PARK*/

/*CREATING DATABASE SCHEMA*/
DROP DATABASE IF EXISTS ZooPark;
CREATE DATABASE ZooPark;

USE ZooPark;

DROP TABLE IF EXISTS CUSTOMER;
CREATE TABLE CUSTOMER (
	Cid VARCHAR(15) NOT NULL, CFname VARCHAR(30) NOT NULL, CLname VARCHAR(30) NOT NULL,
	Email VARCHAR(30) DEFAULT NULL,	Address VARCHAR(100) DEFAULT NULL, Credit_Card_Info VARCHAR(100) DEFAULT NULL,
	PRIMARY KEY(Cid)	
);

DROP TABLE IF EXISTS TICKET;
CREATE TABLE TICKET	(
	Tid VARCHAR(15) NOT NULL, Price INT NOT NULL, Slot VARCHAR(15) NOT NULL,
	Cid VARCHAR(15) NOT NULL,
	PRIMARY KEY(Tid),
	CONSTRAINT fk_ticket_cid FOREIGN KEY (Cid) REFERENCES CUSTOMER(Cid)
	ON DELETE CASCADE	ON UPDATE CASCADE			
);

DROP TABLE IF EXISTS ANIMAL_GUIDE;
CREATE TABLE ANIMAL_GUIDE (
	AGid VARCHAR(15) NOT NULL, Zoo_Introduction TEXT NOT NULL, Updated_Year INT DEFAULT NULL, Slot VARCHAR(15) NOT NULL,
	PRIMARY KEY(AGid)
);

DROP TABLE IF EXISTS ZOO;
CREATE TABLE ZOO (
	Zid VARCHAR(15) NOT NULL, ZName VARCHAR(50) NOT NULL, Location VARCHAR(100) NOT NULL,
	Hours VARCHAR(100) NOT NULL, Contact VARCHAR(100) NOT NULL,
	AGid VARCHAR(15) NOT NULL,
	PRIMARY KEY(Zid),
	CONSTRAINT fk_zoo_AGid FOREIGN KEY (AGid) REFERENCES ANIMAL_GUIDE(AGid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS EMPLOYEE;
CREATE TABLE EMPLOYEE (
	Eid VARCHAR(15) NOT NULL, EFname VARCHAR(30) NOT NULL, ELname VARCHAR(30) NOT NULL,
	Phone_No VARCHAR(30) NOT NULL, Salary INT NOT NULL,
	Zid VARCHAR(15) NOT NULL,
	PRIMARY KEY(Eid),
	CONSTRAINT fk_emp_zid FOREIGN KEY (Zid)	REFERENCES ZOO(Zid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS ANIMAL_KIND;
CREATE TABLE ANIMAL_KIND (
	AKid VARCHAR(15) NOT NULL, AName VARCHAR(30) NOT NULL, Species_Name VARCHAR(30) NOT NULL, 
	Physical_Characteristics TEXT NOT NULL,	Zoo_Region VARCHAR(50) NOT NULL, 
	Diet VARCHAR(30) NOT NULL,	Population_Status VARCHAR(30) NOT NULL,
	PRIMARY KEY(AKid)
);

DROP TABLE IF EXISTS ANIMAL;
CREATE TABLE ANIMAL (
	Aid VARCHAR(15) NOT NULL, Gender VARCHAR(10) DEFAULT NULL, Cage_Number INT NOT NULL, Feed_Time VARCHAR(30) NOT NULL,
	AKid VARCHAR(15) NOT NULL,
	PRIMARY KEY(Aid),
	CONSTRAINT fk_ani_akid FOREIGN KEY (AKid) REFERENCES ANIMAL_KIND(AKid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS ANIMAL_DETAIL;
CREATE TABLE ANIMAL_DETAIL (
	ADid VARCHAR(15) NOT NULL, Height INT DEFAULT NULL, Weight INT DEFAULT NULL, Age INT DEFAULT NULL,
	Aid VARCHAR(15) NOT NULL,
	PRIMARY KEY(ADid),
	CONSTRAINT fk_ad_aid FOREIGN KEY (Aid) REFERENCES ANIMAL(Aid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS GOES_TO;
CREATE TABLE GOES_TO (
	GTid VARCHAR(15) NOT NULL, Cid VARCHAR(15) NOT NULL, Zid VARCHAR(15) NOT NULL,
	PRIMARY KEY(GTid),
	CONSTRAINT fk1_gt_cid FOREIGN KEY (Cid)	REFERENCES CUSTOMER(Cid)
	ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT fk2_gt_zid FOREIGN KEY (Zid) REFERENCES ZOO(Zid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS MANAGES;
CREATE TABLE MANAGES (
	Mid VARCHAR(15) NOT NULL, Eid VARCHAR(15) NOT NULL, Tid VARCHAR(15) NOT NULL,
	PRIMARY KEY(Mid),
	CONSTRAINT fk1_man_eid FOREIGN KEY (Eid) REFERENCES EMPLOYEE(Eid)
	ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT fk2_manages_tid FOREIGN KEY (Tid) REFERENCES TICKET(Tid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS LOOKS_AFTER;
CREATE TABLE LOOKS_AFTER (
	LAid VARCHAR(15) NOT NULL, Eid VARCHAR(15) NOT NULL, Aid VARCHAR(15) NOT NULL,
	PRIMARY KEY(LAid),
	CONSTRAINT fk1_la_eid FOREIGN KEY (Eid)	REFERENCES EMPLOYEE(Eid)
	ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT fk2_looka_aid FOREIGN KEY (Aid) REFERENCES ANIMAL(Aid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

DROP TABLE IF EXISTS ZOO_CONTAINS;
CREATE TABLE ZOO_CONTAINS (
	ZCid VARCHAR(15), AKid VARCHAR(15) NOT NULL, AGid VARCHAR(15) NOT NULL,
	PRIMARY KEY(ZCid),
	CONSTRAINT fk1_cont_akid FOREIGN KEY (AKid) REFERENCES ANIMAL_KIND(AKid)
	ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT fk2_contains_agid FOREIGN KEY (AGid)	REFERENCES ANIMAL_GUIDE(AGid)
	ON DELETE CASCADE ON UPDATE CASCADE
);

ALTER TABLE ANIMAL_KIND
ADD CONSTRAINT chk_Animal_diet CHECK (Diet = 'Carnivore' OR Diet = 'Herbivore' OR Diet = 'Omnivore');

ALTER TABLE TICKET
ADD CONSTRAINT chk_ticket_price CHECK (Price >=800 AND Price <=2500);

ALTER TABLE EMPLOYEE
ADD CONSTRAINT chk_employee_salary CHECK (Salary >=9000 AND Salary <=27000);

ALTER TABLE ANIMAL_GUIDE
ADD CONSTRAINT chk_Animal_slot CHECK (Slot = 'Morning' OR Slot = 'Afternoon' OR Slot = 'Night');


/*INSERTING VALUES*/

USE ZooPark;

INSERT INTO ANIMAL_KIND (AKid, AName, Species_Name, Physical_Characteristics, 
Zoo_Region, Diet, Population_Status) VALUES
('21', 'Elephant', 'Elephas maximus', 'big', 'Z2', 'Omnivore', 'Endangered'),
('22', 'Peacock', 'Pavo cristatus', 'small', 'Z2', 'Omnivore', 'Endangered'),
('23', 'Fox', 'Vulpes vulpes', 'medium', 'Z1', 'Carnivore', 'Not Endangered'),
('24', 'Tiger', 'Panthera Tigris', 'medium', 'Z1', 'Carnivore', 'Endangered'),
('25', 'Zebra', 'Equus quagga', 'medium', 'Z3', 'Herbivore', 'Not Endangered'),
('26', 'Giraffe', 'Giraffa camelopardalis', 'big', 'Z3', 'Herbivore', 'Not Endangered');

INSERT INTO ANIMAL (Aid, Gender, Cage_Number, Feed_Time, AKid) VALUES
('1', 'male', 1, '1:00-1:30pm', '21'),
('2', 'female', 1, '1:00-1:30pm', '21'),
('3', 'male', 2, '2:00-2:30pm', '22'),
('4', 'female', 2, '2:00-2:30pm', '22'),
('5', 'male', 3, '1:00-1:30pm', '23'),
('6', 'female', 3, '1:00-1:30pm', '23'),
('7', 'male', 4, '2:00-2:30pm', '24'),
('8', 'female', 4, '2:00-2:30pm', '24'),
('9', 'male', 5, '3:00-3:30pm', '25'),
('10', 'female', 5, '3:00-3:30pm', '25'),
('11', 'male', 6, '1:00-1:30pm', '26'),
('12', 'female', 6, '1:00-1:30pm', '26');

INSERT INTO ANIMAL_DETAIL (ADid, Height, Weight, Age, Aid) VALUES
('51', 4, 15, 33, '1'),
('52', 15, 120, 43, '2'),
('53', 20, 120, 12, '3'),
('54', 5, 10, 43, '4'),
('55', 17, 140, 43, '5'),
('56', 12, 120, 23, '6'),
('57', 5, 60, 43, '7'),
('58', 13, 120, 43, '8'),
('59', 5, 75, 27, '9'),
('60', 14, 215, 14, '10'),
('61', 5, 70, 43, '11'),
('62', 6, 80, 43, '12');

INSERT INTO ANIMAL_GUIDE (AGid, Zoo_Introduction, Updated_Year, Slot) VALUES
('AG1', 'Educational', 2018, 'Morning'),
('AG2', 'Educational', 2016, 'Afternoon'),
('AG3', 'Educational', 2019, 'Night'),
('AG4', 'Inspection', 2019, 'Morning'),
('AG5', 'Inspection', 2016, 'Afternoon'),
('AG6', 'Inspection', 2019, 'Night'),
('AG7', 'Travel', 2017, 'Morning'),
('AG8', 'Travel', 2019, 'Night');

INSERT INTO CUSTOMER (Cid, CFname, CLname, Email, Address, Credit_Card_Info) VALUES
('C1', 'Amal', 'Sutone', 'amal@gmail.com', 'Nagpur', '12233445533'),
('C2', 'Shubham', 'Maratha', 'sm@gmail.com', 'Bangalore', '12323456765434'),
('C3', 'Babu', 'Rao', 'br@gmail.com', 'Mumbai', '12345567987'),
('C4', 'Shamu', 'Rao', 'sr@gmail.com', 'Bangalore', '12345348987'),
('C5', 'Nina', 'Patel', 'np@gmail.com', 'Bangalore', '12345678269');

INSERT INTO TICKET (Tid, Price, Slot, Cid) VALUES
('T10', 2500, 'Morning', 'C1'),
('T11', 2100, 'Afternoon', 'C2'),
('T12', 2300, 'Night', 'C2'),
('T13', 1400, 'Night', 'C2'),
('T14', 1200, 'Afternoon', 'C3'),
('T15', 1700, 'AFternoon', 'C3'),
('T16', 1700, 'Morning', 'C4'),
('T17', 1800, 'Morning', 'C4'),
('T18', 1900, 'Morning', 'C5');

INSERT INTO ZOO (Zid, Zname, Location, Hours, Contact, AGid) VALUES
('1001', 'RG', 'South', '10', '8787878789', 'AG1'),
('1002', 'ANNA', 'North', '12', '9898989238', 'AG2'),
('1003', 'APPA', 'West', '24', '8787878799', 'AG3'),
('1004', 'QWER', 'South', '24', '1234727272', 'AG4'),
('1005', 'RGR', 'South', '10', '8787878789', 'AG5'),
('1006', 'ALPH', 'East', '12', '9898912238', 'AG6'),
('1007', 'RENN', 'West', '24', '8787812799', 'AG7'),
('1008', 'TREW', 'East', '24', '7271347272', 'AG8');

INSERT INTO EMPLOYEE (Eid, EFname, ELname, Phone_No, Salary, Zid) VALUES
('E101', 'Adarsh', 'Parabhat', '9876612344', 10000, '1001'),
('E102', 'Prajoyat', 'Sharma', '9876173344', 20000, '1001'),
('E103', 'Jack', 'Chaudhary', '9712696969', 24000, '1002'),
('E104', 'Adarsh', 'Patel', '9876211243', 14000, '1002'),
('E105', 'Adarsh', 'Bhatt', '9876712344', 15000, '1003'),
('E106', 'Akarsh', 'Singh', '9123412344', 12000, '1003'),
('E107', 'Aswini', 'Parabhat', '9827172344', 20000, '1004'),
('E108', 'Rose', 'Paul', '9876785435', 13000, '1004'),
('E109', 'Phalak', 'Jain', '9234674583', 12000, '1005'),
('E110', 'Parul', 'Patel', '9167253045', 10000, '1005'),
('E111', 'Jasleen', 'Kumari', '9236792560', 10000, '1006'),
('E112', 'Kumar', 'Singh', '9726385930', 10000, '1006'),
('E113', 'Vaishnavi', 'Vellam', '9871232344', 10000, '1007'),
('E114', 'Rajesh', 'Lalit', '9712609234', 10000, '1008');

INSERT INTO ZOO_CONTAINS (ZCid, AKid, AGid) VALUES
('ZC101', '21', 'AG1'),('ZC102', '22', 'AG1'),('ZC103', '23', 'AG1'),('ZC104', '24', 'AG1'),('ZC105', '25', 'AG1'),('ZC106', '26', 'AG1'),
('ZC107', '21', 'AG2'),('ZC108', '22', 'AG2'),('ZC109', '23', 'AG2'),('ZC110', '24', 'AG2'),('ZC111', '25', 'AG2'),('ZC112', '26', 'AG2'),
('ZC113', '21', 'AG3'),('ZC114', '22', 'AG3'),('ZC115', '23', 'AG3'),('ZC116', '24', 'AG3'),('ZC117', '25', 'AG4'),('ZC118', '26', 'AG4'),
('ZC119', '21', 'AG5'),('ZC120', '22', 'AG5'),('ZC121', '23', 'AG5'),('ZC122', '24', 'AG5'),
('ZC123', '25', 'AG6'),('ZC124', '26', 'AG6'),
('ZC125', '23', 'AG7'),('ZC126', '24', 'AG7'),
('ZC127', '25', 'AG8'),('ZC128', '26', 'AG8');

INSERT INTO LOOKS_AFTER (LAid, Eid, Aid) VALUES
('LA101', 'E101', '1'),('LA102', 'E101', '2'),('LA103', 'E101', '3'),('LA104', 'E101', '4'),
('LA105', 'E101', '5'),('LA106', 'E101', '6'),('LA107', 'E101', '7'),('LA108', 'E101', '8'),
('LA109', 'E102', '9'),('LA110', 'E102', '10'),('LA111', 'E102', '11'),('LA112', 'E102', '12'),
('LA113', 'E103', '1'),('LA114', 'E103', '2'),('LA115', 'E103', '3'),('LA116', 'E103', '4'),
('LA117', 'E103', '5'),('LA118', 'E103', '6'),('LA119', 'E103', '7'),('LA120', 'E103', '8'),
('LA121', 'E104', '9'),('LA122', 'E104', '10'),('LA123', 'E104', '11'),('LA156', 'E104', '12'),
('LA124', 'E105', '1'),('LA125', 'E105', '2'),('LA126', 'E105', '3'),('LA127', 'E105', '4'),
('LA128', 'E105', '5'),('LA129', 'E105', '6'),('LA130', 'E105', '7'),('LA131', 'E105', '8'),
('LA132', 'E107', '9'),('LA133', 'E107', '10'),('LA134', 'E107', '11'),('LA135', 'E107', '12'),
('LA136', 'E109', '1'),('LA137', 'E109', '2'),('LA138', 'E109', '3'),('LA139', 'E109', '4'),
('LA140', 'E109', '5'),('LA141', 'E109', '6'),('LA142', 'E109', '7'),('LA143', 'E109', '8'),
('LA144', 'E111', '9'),('LA145', 'E111', '10'),('LA146', 'E111', '11'),('LA147', 'E111', '12'),
('LA148', 'E113', '5'),('LA149', 'E113', '6'),('LA150', 'E113', '7'),('LA151', 'E113', '8'),
('LA152', 'E114', '9'),('LA153', 'E114', '10'),('LA154', 'E114', '11'),('LA155', 'E114', '12');

INSERT INTO GOES_TO (GTid, Cid, Zid) VALUES 
('GT001', 'C1', '1001'),
('GT002', 'C2', '1002'),
('GT003', 'C2', '1003'),
('GT004', 'C2', '1004'),
('GT005', 'C3', '1005'),
('GT006', 'C3', '1006'),
('GT007', 'C4', '1007'),
('GT008', 'C4', '1008'),('GT009', 'C5', '1008');

INSERT INTO MANAGES (Mid, Eid, Tid) VALUES 
('M001', 'E102', 'T10'),
('M002', 'E104', 'T11'),
('M003', 'E106', 'T12'),
('M004', 'E108', 'T13'),
('M005', 'E110', 'T14'),
('M006', 'E112', 'T15'),
('M007', 'E113', 'T16'),
('M008', 'E114', 'T17'),('M009', 'E114', 'T18');




