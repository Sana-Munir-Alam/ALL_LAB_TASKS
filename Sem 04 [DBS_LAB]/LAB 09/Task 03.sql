-- Uni_Dept
INSERT INTO Uni_Dept VALUES (1, 'Computer Science');
INSERT INTO Uni_Dept VALUES (2, 'Electrical Engineering');
INSERT INTO Uni_Dept VALUES (3, 'Business Administration');

-- Uni_Instructor
INSERT INTO Uni_Instructor VALUES (1, 'Dr. Asim Khan',  'asim@uni.edu',  'Professor',            1);
INSERT INTO Uni_Instructor VALUES (2, 'Dr. Sara Baig',  'sara@uni.edu',  'Associate Professor',   1);
INSERT INTO Uni_Instructor VALUES (3, 'Dr. Usman Ali',  'usman@uni.edu', 'Assistant Professor',   2);
INSERT INTO Uni_Instructor VALUES (4, 'Dr. Nadia Shah', 'nadia@uni.edu', 'Lecturer',              3);

-- Uni_Course
INSERT INTO Uni_Course VALUES (101, 'Database Systems',       3, 'Fall 2025',   1, 1);
INSERT INTO Uni_Course VALUES (102, 'Data Structures',        3, 'Fall 2025',   1, 2);
INSERT INTO Uni_Course VALUES (103, 'Circuit Analysis',       3, 'Spring 2025', 2, 3);
INSERT INTO Uni_Course VALUES (104, 'Business Communication', 2, 'Fall 2025',   3, 4);

-- Uni_Student
INSERT INTO Uni_Student VALUES (201, 'Ali Raza',    'ali@std.edu',   '0321-1111111', 'BSCS');
INSERT INTO Uni_Student VALUES (202, 'Hina Malik',  'hina@std.edu',  '0321-2222222', 'BSCS');
INSERT INTO Uni_Student VALUES (203, 'Bilal Ahmed', 'bilal@std.edu', '0321-3333333', 'BSEE');
INSERT INTO Uni_Student VALUES (204, 'Sana Tariq',  'sana@std.edu',  '0321-4444444', 'BBA');

-- Uni_Enrollment (note: Enrollmennt_ID still has double n)
INSERT INTO Uni_Enrollment VALUES (301, DATE '2025-09-01', 'Fall 2025',   'A',  201, 101);
INSERT INTO Uni_Enrollment VALUES (302, DATE '2025-09-01', 'Fall 2025',   'B',  201, 102);
INSERT INTO Uni_Enrollment VALUES (303, DATE '2025-09-01', 'Fall 2025',   'A',  202, 101);
INSERT INTO Uni_Enrollment VALUES (304, DATE '2025-02-01', 'Spring 2025', 'C',  203, 103);
INSERT INTO Uni_Enrollment VALUES (305, DATE '2025-09-01', 'Fall 2025',   NULL, 204, 104);

COMMIT;

----Query 1
SELECT s.Student_Name, c.Course_Title, i.Instructor_Name, e.Semester, e.Grade FROM Uni_Enrollment  e
JOIN Uni_Student s ON e.Uni_Student_Student_ID = s.Student_ID
JOIN Uni_Course c ON e.Uni_Course_Course_ID = c.Course_ID
JOIN Uni_Instructor i ON c.Uni_Instructor_Instructor_ID = i.Instructor_ID
ORDER BY s.Student_Name;

----Query 2
SELECT c.Course_ID, c.Course_Title, c.Credit_Hrs, i.Instructor_Name, i.Designation_Type FROM Uni_Course c
JOIN Uni_Instructor i ON c.Uni_Instructor_Instructor_ID = i.Instructor_ID
WHERE c.Semester_Offered = 'Fall 2025'
ORDER BY c.Course_Title;
