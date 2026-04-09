#include <iostream>
using namespace std;

class Person{
    // As private
    string Name;
    int Age;

    // As Public
    public:

        void setName(string PersonName){
            Name = PersonName;
        }
        void setAge(int PersonAge){
            Age = PersonAge;
        }
        string getName(){
            return Name;
        }
        int getAge(){
            return Age;
        }

        virtual void displayInfo(){
            cout << "" << endl;
            cout << "Person Details: " << endl;
            cout << "Name: " << getName() << endl;
            cout << "Age: " << getAge() << endl;
        }
};

class Employee : public Person{
    // As Private
    private:
        int EmployeeID;
    public:
        void setID(int E_ID){
            EmployeeID = E_ID;
        }
        int getID(){
            return EmployeeID;
        }
        void displayInfo(){
            cout << "" << endl;
            cout << "Employee Details: " << endl;
            cout << "Name: " << getName() << endl;
            cout << "Age: " << getAge() << endl;
            cout << "ID: " << getID() << endl;
        }
};
class Student : public Person{
    // As Private
    private:
        int StudentID;
    public:
        void setID(int S_ID){
            StudentID = S_ID;
        }
        int getID(){
            return StudentID;
        }
        void displayInfo(){
            cout << "" << endl;
            cout << "Student Details: " << endl;
            cout << "Name: " << getName() << endl;
            cout << "Age: " << getAge() << endl;
            cout << "ID: " << getID() << endl;
        }
};

int main(){
    // Creating Objects of derived classes
    Person* Personptr;
    Employee DataEmployee; 
    Student DataStudent;

    DataEmployee.setName("Umar");
    DataEmployee.setAge(28);
    DataEmployee.setID(423);
    Personptr = &DataEmployee;
    Personptr -> displayInfo();
    cout << endl;

    DataStudent.setName("Munir");
    DataStudent.setAge(18);
    DataStudent.setID(0573);
    Personptr = &DataStudent;
    Personptr -> displayInfo();
    return 0;
}
