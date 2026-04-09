#include <iostream>
#include <cstring>
using namespace std;

class Exam{
    private:
        char* StudentName;  // Using char* here cause we have to use DMA and do shallow copy
        char* ExamDate;     // Using char* here cause we have to use DMA and the string would do deep copy as a safe side (from what i remember).
        int Score;          // Assuming Marks are whole, and not in points

    public:
        Exam(const char* Name, const char* Date, int Marks){    // Parameterized Constructor
            StudentName = new char[strlen(Name) + 1];   // Creating DMA, using strlen to define the size for the data being stored. +1 for the null character inclusion.
            strcpy(StudentName, Name);                  // Copying the argument into variable StudentName
            ExamDate = new char[strlen(Date) + 1];      // Creating DMA, using strlen to define the size for the data being stored. +1 for the null character inclusion.
            strcpy(ExamDate, Date);                     // Copying the argument into variable ExamDate
            Score = Marks;
            cout << "Parameterized Constrcutor at Work\n";
        }
        // SETTERS 
        // (This setter during shallow copy will show the affect of Dangling Pointer)
        void setStudentName(const char* Name){          // Setting student name, using const to avoid accidental change to the data
            if (StudentName != nullptr){                // Check to see if the variable is not empty so that only than FREEING is done otherwise program can crash.
                delete[] StudentName;                   // Freeing old memory incase we are changing an already set data value to avoid memory leaks
            }
            StudentName = new char[strlen(Name) + 1];   // Creating DMA, using strlen to define the size for the data being stored. +1 for the null character inclusion.
            strcpy(StudentName, Name);                  // Copying the argument into variable StudentName
        }
        // (This setter during shallow copy will show the affect of Data changing in both object due to sharing same memory block)
        void setExamDate(const char* Date){             // Setting exam date, using const to avoid accidental change to the data
            strcpy(ExamDate, Date);                     // Copying the argument into variable ExamDate
        }
        void setScore(int Marks){ Score = Marks; }

        ~Exam(){ // Destructor
            cout << "Destrcutor executed for: " << (StudentName ? StudentName : "Unkonwn/nullptr") << endl;
            delete[] StudentName;
            delete[] ExamDate;
        }

        void DisplayInfo(){
            cout << "Student Name: " << StudentName << "\nExam Date: " << ExamDate << "\nScore: " << Score << endl << endl;
        }
};

int main(){
    Exam Student2("Richard", "20-08-2025", 87); // Will Call Parametrized Constrcutor
    Student2.DisplayInfo();                     // Displaying Info

    // DOING SHALLOW COPY
    Exam Student3 = Student2;           // Copying Student 2 Data in Student 3;
    cout << "Copying Student2 to Student3\nNow Displaying Student3\n";
    Student3.DisplayInfo();             // Displaying Student 3 info.

    // Case I: Showing how shallow copy affects both the object when one gets changed;
    // This frees the old memory ("Richard") and allocates "Christopher".
    // But Student2 is still pointing to the freed memory from Student3.
    // So Student2’s name becomes a dangling pointer → garbage value.
    cout << "CASE I: Dangling Pointer Issue when memory is freed to write a new data" << endl;
    Student3.setStudentName("Christopher");
    cout << "Displaying Student 3 Info after changing Name:\n"; 
    Student3.DisplayInfo();
    cout << "\nDisplaying Student 2 Info after Student 3 Name was changed\n";   // We see garbage value in place of name,
    Student2.DisplayInfo();

    // Case II:
    // Since Student3 & Student2 share SAME examDate pointer,
    // updating through Student3 also changes Student3.
    cout << "CASE II: Both the object value change due to shared memory but will cause double deletion during Destruction" << endl;
    Student3.setExamDate("25-02-2026");
    cout << "Displaying Student 3 Info after changing Date:\n"; 
    Student3.DisplayInfo();
    cout << "\nDisplaying Student 2 Info after Student 3 Date was changed\n"; // We see both the object show the same NEW date for they share that memory.
    Student2.DisplayInfo();
    return 0;
}
