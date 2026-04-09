#include <iostream>

using namespace std;

int main(){
	cout << "=========STATIC ARRAY=========\n\n";
    int arr[5] = {10,20,30,40,50};  // Creating A One Dimension Array
	cout << "~---1D array---~";
    cout << "\nFirst Index Value:";
    cout << arr[0] <<endl;
	
	cout << "Printing 1D-Array Content\n"; 
    for(int i = 0; i < 5; i++){				// Printing the Content of Array
        cout << arr[i] << " ";
    }
    cout << "\nSize of Array[total memory space]: " << sizeof(arr) << endl;
    cout << "Size of Array[quantity]: " << sizeof(arr)/sizeof(arr[0]) <<endl;
    
    
    int NewArray[2][3] = {{1,2,3},{4,5,6}};	// Creating A two Dimension Array
    cout << "\n~---2D array---~\n";
	cout << "First Index Value:";
    cout << NewArray[0][0] <<endl;
    cout << "Printing 2D-Array Content\n";
    for(int i = 0; i < 2; i++){				// Printing the Content of Array
    	for(int j = 0; j < 3; j++){
    		cout << NewArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Size of Array[total memory space]: " << sizeof(NewArray) << endl;
    cout << "Size of Array[quantity]: " << sizeof(NewArray)/sizeof(NewArray[0][0]) <<endl;
    
    // DYNAMIC ARRAY
    cout << "\n\n=========DYNAMIC ARRAY=========\n\n";
    cout << "~---1D array---~";
    int n;
    cout << "\nEnter the size of 1D Array you want: ";
    cin >> n;
    int *DynamicArr = new int[n];	// DMA to create space for the array on run time as per user requirement
    cout << "Enter " <<n << " elements: \n";
    for (int i = 0; i < n; i++){	// Storing User input in the Array
    	cin >> DynamicArr[i];
	}
	cout << "Printing 1D-Array Content\n"; 
	for(int i = 0; i < n; i++){				// Printing the Content of Array
        cout << DynamicArr[i] << " ";
    }
    
    cout << "\n\n~---2D array---~\n";
    int Row, Col;
    cout << "Enter The Row: ";
    cin >> Row;
    cout << "Enter the Columns: ";
    cin >> Col;
    // Dynamically Allocating Memory Space to Rows and Array for the 2D-Array
    int **DynamicArray = new int*[Row];
    for (int i = 0 ; i < Row; i++){
    	DynamicArray[i] = new int[Col];
	}
	// Storing User input in the Array
	cout << "Enter Elements for 2D Array: \n";
    for (int i = 0; i < Row; i++){	
    	for (int j = 0; j < Col; j++){
    		cin >> DynamicArray[i][j];
		}
	}
	cout << "Printing 2D-Array Content\n"; 
	for(int i = 0; i < Row; i++){				
        for (int j = 0; j < Col; j++){
    		cout << DynamicArray[i][j] << " ";
		}
		cout << endl;
    }
    // Freeing 1D Array
    delete[] DynamicArr;    
    // Freeing 2D Array
    for (int i = 0; i < Row; i++){
        delete[] DynamicArray[i];
    }
    delete[] DynamicArray;


    // JAGGED ARRAY
    cout << "\n\n=========JAGGED ARRAY=========\n\n";
    int r = 3;  // Number of ROws
    int size[3];
    cout << "This Jagged Array has fixed 3 rows no kindly add the number of colunms you want for each row!!" <<endl;
    // Dynamically Allocating Memory Space to Rows[fixed size of 3 for this case] and Array for the 2D-Array
    int ** JaggedArr = new int*[r];
    for (int i = 0; i < r; i++){
        cout << "Enter Size of Col for Row " << i << ": ";
        cin >> size[i];
        JaggedArr[i] = new int[size[i]];    // Creating Jagged Colunms
    }
    cout << "Enter Elements for Jagged 2D Array: \n";
    for (int i = 0; i < r; i++){	
    	for (int j = 0; j < size[i]; j++){
    		cin >> JaggedArr[i][j];
		}
	}
    cout << "Printing Jagged 2D-Array Content:\n"; 
	for(int i = 0; i < r; i++){				
        for (int j = 0; j < size[i]; j++){
    		cout << JaggedArr[i][j] << " ";
		}
		cout << endl;
    }

    return 0;
}

// // This function is done to make sure that our Array doesnt go out of memory
// void safe(int pos, Element Val){
//     if(pos < 0 || pos >= Size){ // Safe Check for boundary
//         cout << "Boundary Error\n";
//     }else{
//         Array[pos] = Val;
//     }
// }

