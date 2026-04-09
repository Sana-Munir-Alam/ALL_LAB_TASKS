----Q1
CREATE TABLE DEPARTMENT (
   dept_id    NUMBER PRIMARY KEY,
   dept_name  VARCHAR2(50),
   location   VARCHAR2(50)
);


---- Q2
CREATE TABLE EMPLOYEE_BASIC (
   emp_id     NUMBER PRIMARY KEY NOT NULL,
   full_name  VARCHAR2(60) NOT NULL,
   email      VARCHAR2(80) UNIQUE,
   phone      VARCHAR2(20),
   hire_date  DATE
);


---- Q3
CREATE TABLE JOB_ROLE (
   job_id      NUMBER PRIMARY KEY,
   job_title   VARCHAR2(40),
   max_salary  NUMBER,
   min_salary  NUMBER DEFAULT 20000,
   CHECK (min_salary < max_salary)
);


----Q4
CREATE TABLE EMPLOYEE_PERSONAL (
   emp_id         NUMBER PRIMARY KEY,
   gender         CHAR(1) CHECK (gender IN ('M','F')),
   date_of_birth  DATE,
   marital_status VARCHAR2(10) CHECK (marital_status IN ('SINGLE','MARRIED'))
);


-----Q5
CREATE TABLE EMPLOYEE_WORK (
   emp_id       NUMBER PRIMARY KEY,
   dept_id      NUMBER,
   job_id       NUMBER,
   joining_date DATE,
   CONSTRAINT fk_empwork_dept FOREIGN KEY (dept_id) REFERENCES DEPARTMENT(dept_id),
   CONSTRAINT fk_empwork_job FOREIGN KEY (job_id) REFERENCES JOB_ROLE(job_id)
);


----Q6
CREATE TABLE PROJECT (
   project_id   NUMBER PRIMARY KEY,
   project_name VARCHAR2(60),
   start_date   DATE,
   end_date     DATE,
   CHECK (end_date > start_date)
);


----Q7
CREATE TABLE PROJECT_ASSIGNMENT (
   emp_id       NUMBER,
   project_id   NUMBER,
   assigned_date DATE,
   CONSTRAINT pk_project_assignment PRIMARY KEY (emp_id, project_id),
   CONSTRAINT fk_pa_emp FOREIGN KEY (emp_id) REFERENCES EMPLOYEE_WORK(emp_id),
   CONSTRAINT fk_pa_project FOREIGN KEY (project_id) REFERENCES PROJECT(project_id)
);


----Q8
ALTER TABLE PROJECT_ASSIGNMENT DROP CONSTRAINT fk_pa_project;

ALTER TABLE PROJECT_ASSIGNMENT ADD CONSTRAINT fk_pa_project
FOREIGN KEY (project_id) REFERENCES PROJECT(project_id)
ON DELETE CASCADE;


----Q9
ALTER TABLE EMPLOYEE_WORK DROP CONSTRAINT fk_empwork_dept;

ALTER TABLE EMPLOYEE_WORK
ADD CONSTRAINT fk_empwork_dept FOREIGN KEY (dept_id) REFERENCES DEPARTMENT(dept_id)
ON DELETE SET NULL;


----Q10
CREATE TABLE CLIENT (
   client_id   NUMBER,
   client_name VARCHAR2(40),
   email       VARCHAR2(60),
   client_type VARCHAR2(20),
   country     VARCHAR2(30)
);


----Q11
ALTER TABLE CLIENT
ADD CONSTRAINT pk_client PRIMARY KEY (client_id);

ALTER TABLE CLIENT
ADD CONSTRAINT uq_client_email UNIQUE (email);

ALTER TABLE CLIENT
ADD CONSTRAINT chk_client_type CHECK (client_type IN ('LOCAL','INTERNATIONAL'));


----Q12
ALTER TABLE CLIENT MODIFY client_name VARCHAR2(80);

ALTER TABLE CLIENT MODIFY email NOT NULL;

ALTER TABLE CLIENT MODIFY country DEFAULT 'PAKISTAN';


----Q13
ALTER TABLE CLIENT DROP CONSTRAINT chk_client_type;

ALTER TABLE CLIENT RENAME CONSTRAINT uq_client_email TO uq_client_email_address;


----Q14
CREATE TABLE EMPLOYEE_BACKUP AS SELECT * FROM EMPLOYEE_WORK;


----Q15
CREATE TABLE PAYROLL (
   emp_id    NUMBER,
   salary    NUMBER CHECK (salary >= 0),
   bonus     NUMBER DEFAULT 0 CHECK (bonus >= 0),
   deduction NUMBER DEFAULT 0 CHECK (deduction >= 0),
   pay_date  DATE,
   CONSTRAINT pk_payroll PRIMARY KEY (emp_id, pay_date),
   CONSTRAINT fk_payroll_emp FOREIGN KEY (emp_id) REFERENCES EMPLOYEE_WORK(emp_id)
);


----Q16
CREATE TABLE ATTENDANCE (
   attendance_id   NUMBER PRIMARY KEY,
   emp_id          NUMBER,
   project_id      NUMBER,
   dept_id         NUMBER,
   attendance_date DATE,
   CONSTRAINT fk_att_emp FOREIGN KEY (emp_id) REFERENCES EMPLOYEE_WORK(emp_id),
   CONSTRAINT fk_att_project FOREIGN KEY (project_id) REFERENCES PROJECT(project_id),
   CONSTRAINT fk_att_dept FOREIGN KEY (dept_id) REFERENCES DEPARTMENT(dept_id)
);


----Q17
ALTER TABLE PROJECT_ASSIGNMENT DISABLE CONSTRAINT fk_pa_emp;

ALTER TABLE PROJECT_ASSIGNMENT ENABLE CONSTRAINT fk_pa_emp;


----Q18
CREATE TABLE LEAVE_APPLICATION (
   leave_id    NUMBER PRIMARY KEY,
   emp_id      NUMBER,
   start_date  DATE,
   end_date    DATE,
   leave_days  NUMBER,
   CONSTRAINT chk_leave_days CHECK (leave_days <= 30),
   CONSTRAINT chk_leave_dates CHECK (end_date > start_date),
   CONSTRAINT fk_leave_emp FOREIGN KEY (emp_id) REFERENCES EMPLOYEE_WORK(emp_id)
);


----Q19
DROP TABLE DEPARTMENT CASCADE CONSTRAINTS;


----Q20
CREATE TABLE UNIVERSITY_DEPARTMENT (
    dept_id   NUMBER PRIMARY KEY,
    dept_name VARCHAR2(60) UNIQUE,
    location  VARCHAR2(50)
);

CREATE TABLE INSTRUCTOR (
    instructor_id NUMBER PRIMARY KEY,
    full_name     VARCHAR2(80) NOT NULL,
    email         VARCHAR2(80) UNIQUE,
    hire_date     DATE DEFAULT SYSDATE,
    dept_id       NUMBER,
    CONSTRAINT fk_instr_dept FOREIGN KEY (dept_id)REFERENCES UNIVERSITY_DEPARTMENT(dept_id)
);

CREATE TABLE STUDENT (
    student_id NUMBER PRIMARY KEY,
    full_name  VARCHAR2(80) NOT NULL,
    email      VARCHAR2(80) UNIQUE,
    gender     CHAR(1) CHECK (gender IN ('M','F')),
    dob        DATE,
    dept_id    NUMBER,
    CONSTRAINT fk_student_dept FOREIGN KEY (dept_id) REFERENCES UNIVERSITY_DEPARTMENT(dept_id)
);

CREATE TABLE COURSE (
    course_id    NUMBER PRIMARY KEY,
    course_title VARCHAR2(80) NOT NULL,
    credits      NUMBER DEFAULT 3 CHECK (credits BETWEEN 1 AND 5),
    dept_id      NUMBER,
    instructor_id NUMBER,
    CONSTRAINT fk_course_dept FOREIGN KEY (dept_id) REFERENCES UNIVERSITY_DEPARTMENT(dept_id),
    CONSTRAINT fk_course_instr FOREIGN KEY (instructor_id) REFERENCES INSTRUCTOR(instructor_id)
);

CREATE TABLE ENROLLMENT (
    student_id NUMBER,
    course_id  NUMBER,
    enroll_date DATE DEFAULT SYSDATE,
    grade VARCHAR2(2) CHECK (grade IN ('A','B','C','D','F')),
    CONSTRAINT pk_enrollment PRIMARY KEY (student_id, course_id),
    CONSTRAINT fk_enroll_student FOREIGN KEY (student_id)REFERENCES STUDENT(student_id),
    CONSTRAINT fk_enroll_course FOREIGN KEY (course_id) REFERENCES COURSE(course_id)
);
