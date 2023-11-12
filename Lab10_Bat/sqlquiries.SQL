//1
SELECT StdFirstName, StdLastName, StdCity, StdGPA
FROM Student
WHERE StdGPA > 3.7;

//2
SELECT StdFirstName, StdLastName, StdGPA
FROM Student
ORDER BY StdGPA DESC;

//3
SELECT *
FROM Course
WHERE CourseNo LIKE 'IS%' AND CrsDesc LIKE '%SENIOR%';

//4
SELECT OfferingNumber, CourseNo
FROM Offering
WHERE OffTerm = 'SUMMER' AND FacNo IS NULL;

//5
SELECT O.OfferNo, O.CourseNo, F.FacFirstName, F.FacLastName
FROM Offering O
JOIN Faculty F ON O.FacNo = F.FacNo
WHERE O.OffTerm = 'SPRING' AND F.FacRank = 'ASST' AND O.FacNo = F.FacNo;


//6
SELECT DISTINCT FacNo
FROM Offering
WHERE FacNo IS NOT NULL;


//7
SELECT StdFirstName
FROM Student
WHERE StdCity = 'Bothell'
UNION
SELECT FacFirstName
FROM Faculty
WHERE FacCity = 'Bellevue';


//8
INSERT INTO Student (StdNo, StdFirstName, StdLastName, StdCity, StdState, StdZip, StdMajor, StdClass, StdGPA)
VALUES ('999-99-9999', 'John', 'Doe', 'Lawrence', 'KS', '66045', 'Finance', 'Freshman', 4.0);

SELECT * FROM Student;


//9
UPDATE Student
SET StdMajor = 'Acct'
WHERE StdFirstName = 'Homer' AND StdLastName = 'Wells';

SELECT * FROM Student;


//10
SELECT *
FROM Student S
JOIN Faculty F ON S.StdNo = F.FacNo;
