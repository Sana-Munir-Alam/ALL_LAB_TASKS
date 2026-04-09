#include <iostream>
using namespace std;

int main(){
    cout << "~---TASK 2---~\n";
    int Row, Col;
    cout << "Enter The Student Quantity [Row]: ";
    cin >> Row;
    cout << "Enter the Subject Quantity [Columns]: ";
    cin >> Col;
    // Dynamically Allocating Memory Space to Rows and Array for the 2D-Array
    int **DynamicArray = new int*[Row];
    for (int i = 0 ; i < Row; i++){
    	DynamicArray[i] = new int[Col];
	}
	// Storing User input in the Array
	cout << "Enter Marks for Each Student: \n";
    for (int i = 0; i < Row; i++){	
    	for (int j = 0; j < Col; j++){
    		cin >> DynamicArray[i][j];
		}
	}
	cout << "\nPrinting 2D-Array Content\n"; 
	for(int i = 0; i < Row; i++){	
        cout << "Student " << i+1 << ":";			
        for (int j = 0; j < Col; j++){
    		cout << DynamicArray[i][j] << " ";
		}
		cout << endl;
    }
  
    // Total Marks
    int Total[Row]={0};
    cout << "\nPrinting Total Marks For Each Student\n";
    for(int i = 0; i < Row; i++){
        for (int j = 0; j < Col; j++){
            Total[i] += DynamicArray[i][j];
		}
        cout << "Student " << i+1 << " Total Marks:" << Total[i] << " ";
		cout << endl;
    }

    // Average Marks for each Subject
    int Average;
    cout << "\nPrinting Average Marks For Each Subject [used int so the value is rounded off\n";
    for(int i = 0; i < Col; i++){
        int TotalMarks = 0;      // Resetting the variable for next Subject Total
        Average = 0;    // Resetting the variable for next Subject Average	
        for (int j = 0; j < Row; j++){
            TotalMarks += DynamicArray[j][i];
		}
        Average = TotalMarks / Row; // Total Marks of Subject / Number of Students
        cout << "Subject " << i+1 << " Average Marks:" << Average << " ";
		cout << endl;
    }

	// Highest Marks Student
	int Max = 0;
	int StudentIndex = 0;
	for (int i = 0; i < Row; i++){
		if (Total[i] > Max){
			Max = Total[i];
			StudentIndex = i+1;
		}
	}
	cout << "\nThe Highest Mark is: " << Max << " of Student Number: " << StudentIndex;
    // Freeing 2D Array
    for (int i = 0; i < Row; i++){
        delete[] DynamicArray[i];
    }
    delete[] DynamicArray;

    return 0;
}
