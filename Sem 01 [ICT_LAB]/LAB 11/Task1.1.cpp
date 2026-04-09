#include <iostream>
#include <string>
using namespace std;

class Payable {
    public:
        virtual void calculateSalary() = 0;
};

class Person {
    private:
        string name;
        int age;
        string address;
    public:
        Person(string name, int age, string address) {
            this->name = name;
            this->age = age;
            this->address = address;
        }
        virtual void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Address: " << address << endl;
        }
};

class Student : public Person {
    private:
        string studentID;
        int grade1, grade2, grade3;

    public:
        Student(string name, int age, string address, string studentID)
            : Person(name, age, address), studentID(studentID) {}
        void addGrades(int g1, int g2, int g3) {
            grade1 = g1;
            grade2 = g2;
            grade3 = g3;
        }
        double calculateGPA() {
            return (grade1 + grade2 + grade3) / 3.0;
        }
        void displayDetails() override {
            Person::displayDetails();
            cout << "Student ID: " << studentID << endl;
            cout << "Grades: " << grade1 << " " << grade2 << " " << grade3 << endl;
            cout << "GPA: " << calculateGPA() << endl;
        }
};

class Teacher : public Person, public Payable {
    private:
        string teacherID;
        string subject;
        int numClassesTaught;
        double ratePerClass;
        double salary;
    public:
        Teacher(string name, int age, string address, string teacherID, string subject, int numClassesTaught, double ratePerClass)
            : Person(name, age, address), teacherID(teacherID), subject(subject), numClassesTaught(numClassesTaught), ratePerClass(ratePerClass) {}
        void assignGrade(Student &student, int g1, int g2, int g3) {
            student.addGrades(g1, g2, g3);
        }
        void calculateSalary() override {
            salary = numClassesTaught * ratePerClass;
        }
        void displayDetails() override {
            Person::displayDetails();
            cout << "Teacher ID: " << teacherID << endl;
            cout << "Subject: " << subject << endl;
            cout << "Salary: " << salary << endl;
        }
        void displaySalary() {
            cout << "Teacher's Total Salary: " << salary << endl;
        }
};

int main() {
    Teacher teacher("Sana", 35, "123 Clifton", "NS1001", "Math", 20, 50.0);
   
    Student student1("Adeena", 18, "456 Karachi", "S1001");
    Student student2("Alina", 19, "789 Sindh", "S1002");

    teacher.assignGrade(student1, 85, 90, 88);
    teacher.assignGrade(student2, 78, 82, 80);
   
    teacher.calculateSalary();

    cout << "\nStudent 1 Details: " << endl;
    student1.displayDetails();

    cout << "\nStudent 2 Details: " << endl;
    student2.displayDetails();

    cout << "\nTeacher Details: " << endl;
    teacher.displayDetails();
    teacher.displaySalary();

    return 0;
}
