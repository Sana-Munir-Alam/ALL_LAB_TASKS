#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int NumDepartments;
    
    cout << "Enter the number of departments: ";
    cin >> NumDepartments;
    
    int* StudentsPerDept = new int[NumDepartments]; // Dynamic array to store number of Students in each department
    
    // Get number of Students for each department (btw this will ake it a jagged array)
    for(int i = 0; i < NumDepartments; i++) {
        cout << "Enter number of Students in department " << (i+1) << ": ";
        cin >> StudentsPerDept[i];
    }
    
    // Create dynamic 3D array for Marks
    // First dimension[row]: departments
    // Second dimension[col]: Students in each department
    // Third dimension: 5 Subjects per Student
    double*** Marks = new double**[NumDepartments];
    
    for(int i = 0; i < NumDepartments; i++) {           // Traversing Department [Row]
        Marks[i] = new double*[StudentsPerDept[i]];     // Creating Number of Students Cols in a sepecific Department
        for(int j = 0; j < StudentsPerDept[i]; j++) {   // Traversing Student [Coloumn]
            Marks[i][j] = new double[5];                // Creating 5 Subjects per Student [Assumbe Z axix aisle]
        }
    }
    
    // Input Marks for each department
    for(int Dept = 0; Dept < NumDepartments; Dept++) {
        cout << "\n--- Department " << (Dept + 1) << " ---" << endl;
        for(int Student = 0; Student < StudentsPerDept[Dept]; Student++) {
            cout << "Enter Marks for Student " << (Student + 1) << " (5 Subjects): ";
            for(int Subject = 0; Subject < 5; Subject++) {
                cin >> Marks[Dept][Student][Subject];
            }
        }
    }
    
    // Calculate and display statistics for each department
    cout << "\n======================================================================" << endl;
    cout << "DEPARTMENT STATISTICS" << endl;
    cout << "======================================================================"<< endl;
    
    for(int Dept = 0; Dept < NumDepartments; Dept++) {
        double TotalMarks = 0;
        double Highest = Marks[Dept][0][0]; 
        double Lowest = Marks[Dept][0][0];
        int TotalSubjects = StudentsPerDept[Dept] * 5;
        
        // Calculate Total, Highest, and Lowest Marks for the department
        for(int Student = 0; Student < StudentsPerDept[Dept]; Student++) {
            for(int Subject = 0; Subject < 5; Subject++) {
                double CurrentMark = Marks[Dept][Student][Subject];
                TotalMarks += CurrentMark;
                
                if(CurrentMark > Highest) { Highest = CurrentMark; }
                if(CurrentMark < Lowest) { Lowest = CurrentMark; }
            }
        }
        
        double average = TotalMarks / TotalSubjects;
        
        // Display results for current department
        cout << "\nDepartment " << (Dept + 1) << ":" << endl;
        cout << "  Number of Students: " << StudentsPerDept[Dept] << endl;
        cout << "  Total Marks Evaluated: " << TotalSubjects << endl;
        cout << fixed << setprecision(2);
        cout << "  Highest Mark: " << Highest << endl;
        cout << "  Lowest Mark: " << Lowest << endl;
        cout << "  Average Mark: " << average << endl;
        cout << "----------------------------------------" << endl; 
    }
    
    // Clean up dynamic memory
    for(int i = 0; i < NumDepartments; i++) {
        for(int j = 0; j < StudentsPerDept[i]; j++) {       // Delete Z index
            delete[] Marks[i][j];
        }
        delete[] Marks[i];                                  // Delete Cols
    }
    delete[] Marks;                                         // Delete Row
    delete[] StudentsPerDept;
    
    return 0;
}
