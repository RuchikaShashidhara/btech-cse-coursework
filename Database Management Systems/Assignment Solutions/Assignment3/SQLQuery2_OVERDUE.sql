-- Microsoft SQL Script that retrieves the list of books that became overdue yesterday

USE LIBRARY;

DROP TABLE IF EXISTS BOOKOVERDUE;

-- Creating a Table OVERDUE that contains columns - Book_Title and Borrower_Name
CREATE TABLE BOOKOVERDUE (
Book_Title VARCHAR(30),
Borrower_Name VARCHAR(30)
);

-- Inserting the Book_Titles and Borrower_Names for books that became overdue yesterday
INSERT INTO BOOKOVERDUE
SELECT B.Title, BOR.Name
FROM BOOK_LOANS AS BL, BORROWER AS BOR, BOOK AS B
WHERE DATEDIFF(year, DATEADD(day, -1, SYSDATETIME()), Due_date) <= 0 AND
	  DATEDIFF(month, DATEADD(day, -1, SYSDATETIME()), Due_date) <= 0 AND
	  DATEDIFF(day, DATEADD(day, -1, SYSDATETIME()), Due_date) <= 0 AND
	  BOR.Card_no = BL.Card_no AND B.Book_id = BL.Book_id;

SELECT * FROM BOOKOVERDUE;

