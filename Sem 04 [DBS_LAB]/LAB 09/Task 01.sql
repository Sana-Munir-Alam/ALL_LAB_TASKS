-- Departments
INSERT INTO Departments VALUES (1, 'Cardiology');
INSERT INTO Departments VALUES (2, 'Neurology');
INSERT INTO Departments VALUES (3, 'Orthopedics');

-- Doctors
INSERT INTO Doctors VALUES (101, 'Dr. Ahmed Khan',   'Cardiologist',  2000, 1);
INSERT INTO Doctors VALUES (102, 'Dr. Sara Ali',     'Cardiologist',  2500, 1);
INSERT INTO Doctors VALUES (103, 'Dr. Usman Malik',  'Neurologist',   1800, 2);
INSERT INTO Doctors VALUES (104, 'Dr. Fatima Raza',  'Orthopedist',   1500, 3);

-- Patients
INSERT INTO Patients VALUES (201, 'Ali Raza',    'M', 35, '0321-1111111', 'Karachi');
INSERT INTO Patients VALUES (202, 'Hina Malik',  'F', 28, '0321-2222222', 'Lahore');
INSERT INTO Patients VALUES (203, 'Bilal Ahmed', 'M', 45, '0321-3333333', 'Islamabad');

-- Appointments
INSERT INTO Appointments VALUES (301, DATE '2026-04-20', TIMESTAMP '2026-04-20 10:00:00', 'Completed',  101, 201);
INSERT INTO Appointments VALUES (302, DATE '2026-04-22', TIMESTAMP '2026-04-22 11:30:00', 'Completed',  102, 202);
INSERT INTO Appointments VALUES (303, DATE '2026-04-25', TIMESTAMP '2026-04-25 09:00:00', 'Scheduled',  103, 203);
INSERT INTO Appointments VALUES (304, DATE '2026-04-27', TIMESTAMP '2026-04-27 14:00:00', 'Scheduled',  101, 202);
INSERT INTO Appointments VALUES (305, DATE '2026-04-28', TIMESTAMP '2026-04-28 16:00:00', 'Cancelled',  104, 201);

COMMIT;

----Query 1
SELECT a.Appointment_ID, p.Patient_Name, d.Doctor_Name, dep.Department_Name, a.Appointment_Date, a.Status FROM Appointments a
    JOIN Patients    p   ON a.Patients_Patient_ID      = p.Patient_ID
    JOIN Doctors     d   ON a.Doctors_Doctor_ID         = d.Doctor_ID
    JOIN Departments dep ON d.Departments_Department_ID = dep.Department_ID
ORDER BY a.Appointment_Date;

----Query 2
SELECT d.Doctor_ID, d.Doctor_Name, d.Specialization, d.Consultation_Fee FROM Doctors d
JOIN Departments dep ON d.Departments_Department_ID = dep.Department_ID
WHERE dep.Department_Name = 'Cardiology'
ORDER BY d.Consultation_Fee DESC;
