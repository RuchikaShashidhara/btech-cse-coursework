# Python program to retrieve the list of books that became overdue yesterday
# and print the book title and borrower name for each

import pyodbc
conn = pyodbc.connect('Driver={ODBC Driver 17 for SQL Server};'
                      'Server=DESKTOP-D3J42JA;'
                      'Database=LIBRARY;'
                      'Trusted_Connection=yes;')

cursor = conn.cursor()
#start
cursor.execute("""USE LIBRARY""")
cursor.execute("""DROP TABLE IF EXISTS BOOKOVERDUE""")
# Creating a Table OVERDUE that contains columns - Book_Title and Borrower_Name
cursor.execute("""CREATE TABLE BOOKOVERDUE ( Book_Title VARCHAR(30),
                                             Borrower_Name VARCHAR(30) )""")
# Inserting the Book_Titles and Borrower_Names for books that became overdue yesterday
cursor.execute("""INSERT INTO BOOKOVERDUE
                  SELECT B.Title, BOR.Name
                  FROM BOOK_LOANS AS BL, BORROWER AS BOR, BOOK AS B
                  WHERE DATEDIFF(year, DATEADD(day, -1, SYSDATETIME()), Due_date) <= 0 AND
                        DATEDIFF(month, DATEADD(day, -1, SYSDATETIME()), Due_date) <= 0 AND
            	        DATEDIFF(day, DATEADD(day, -1, SYSDATETIME()), Due_date) <= 0 AND
            	        BOR.Card_no = BL.Card_no AND B.Book_id = BL.Book_id""")
#end
cursor.execute("""SELECT * FROM BOOKOVERDUE""")

# Printing the Book_Titles and Borrower_Names for books that became overdue yesterday
print("Database: LIBRARY\n")
print("Overdue books -")
print("Book Title\t\t\t    Borrower\n")
for row in cursor:
        print('{:<35} {:<35}'.format(*row))

