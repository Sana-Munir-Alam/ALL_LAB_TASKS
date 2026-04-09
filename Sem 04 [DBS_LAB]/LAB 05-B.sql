CREATE TABLE Students (
    student_id NUMBER PRIMARY KEY,
    student_name VARCHAR2(50),
    department VARCHAR2(50),
    semester NUMBER
);

CREATE TABLE Courses (
    course_id NUMBER PRIMARY KEY,
    course_name VARCHAR2(50),
    credit_hours NUMBER
);

CREATE TABLE Enrollments (
    enroll_id NUMBER PRIMARY KEY,
    student_id NUMBER,
    course_id NUMBER,
    grade VARCHAR2(2),
    CONSTRAINT fk_student
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    CONSTRAINT fk_course
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);

----Q1
INSERT INTO Students VALUES (101, &#39;Ali Khan&#39;, &#39;CS&#39;, 3);

----Q2)

INSERT INTO Students VALUES (102, &#39;Sara Ahmed&#39;, &#39;AI&#39;, 2);

----Q3)
INSERT INTO Courses VALUES (501, &#39;Database System&#39;, 3);

----Q4)
INSERT INTO Courses VALUES (502, &#39;Operating System&#39;, 4);

----Q5)
INSERT INTO Enrollments VALUES (1, 101, 501, &#39;A&#39;);

----Q6)
UPDATE STUDENTS
SET SEMESTER = 3
WHERE Student_ID = 102;

SELECT * FROM STUDENTS;

----Q7)
UPDATE COURSES
SET CREDIT_HOURS = 4
WHERE Course_ID = 501;

SELECT * FROM COURSES;

----Q8)
UPDATE ENROLLMENTS
SET GRADE = &#39;A+&#39;
WHERE Student_ID = 101 AND Course_ID = 501;

SELECT * FROM ENROLLMENTS;

----Q9)
DELETE FROM STUDENTS
WHERE Student_ID = 102;

SELECT * FROM STUDENTS;

----Q10)
DELETE FROM COURSES
WHERE Course_ID = 502;

SELECT * FROM COURSES;