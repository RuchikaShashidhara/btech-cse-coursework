# Python program to read a Student's name and print his/her Grade Point Average,
# assuming that A=4, B=3, C=2, D=1 points

import pyodbc
conn = pyodbc.connect('Driver={ODBC Driver 17 for SQL Server};'
                      'Server=DESKTOP-D3J42JA;'
                      'Database=UNIVERSITY;'
                      'Trusted_Connection=yes;')

cursor = conn.cursor()
#start
cursor.execute("""USE UNIVERSITY""")
cursor.execute("""DROP VIEW IF EXISTS GRADES""")
# Creating a View GRADES that contains the Student Name
# and His/Her Grades in numbers(0-4) for each Course
cursor.execute("""CREATE VIEW GRADES(STnum, GRnum) AS
                  SELECT S.Name,
                         CASE WHEN GR.Grade = 'A' THEN 4.0
                              WHEN GR.Grade = 'B' THEN 3.0
                              WHEN GR.Grade = 'C' THEN 2.0
                              WHEN GR.Grade = 'D' THEN 1.0
                              ELSE 0.0
                         END
                  FROM dbo.STUDENT AS S, dbo.GRADE_REPORT AS GR
                  WHERE S.Student_number = GR.Student_number""")
cursor.execute("""DROP TABLE IF EXISTS FINALGPA""")
# Creating a Table FINALGPA with column names Student_Name and Student_GPA
cursor.execute("""CREATE TABLE FINALGPA ( Student_Name VARCHAR(30) NOT NULL,
                                          Student_GPA FLOAT(10) NOT NULL
                                          PRIMARY KEY (Student_Name) )""")
# Inserting the final GPA for each Student_Name (Student)
cursor.execute("""INSERT INTO FINALGPA
                  SELECT STnum, CAST(AVG(GRnum) AS DECIMAL(10, 2)) AS GPA
                  FROM dbo.GRADES
                  GROUP BY STnum """)
#end
cursor.execute("""SELECT * FROM FINALGPA""")

# finalgpa dictionary contains the Student_Name as keys and GPA as values
finalgpa = dict()
for row in cursor:
    finalgpa[row[0]] = row[1]

# Retrieving the Student's name and printing his/her GPA
# If the Student's name is not present in the Database, not found error is thrown
print("Database: UNIVERSITY\n")
print("Enter the Student's Name to get his/her GPA: ")
st = input()
try:
    print("\nStudent's Name:\t", st, "\nStudent's GPA:\t", finalgpa[st])
except KeyError:
    print("\nError:", st, "NOT FOUND")



