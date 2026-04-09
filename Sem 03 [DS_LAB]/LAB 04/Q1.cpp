#include <iostream>
using namespace std;

// Function to print Array elements
void PrintArray(int Array[], int Size, string message = "Array: ") {
    cout << message;
    for (int i = 0; i < Size; i++) {
        cout << Array[i] << " ";
    }
    cout << "}"<<endl;
}

// Function to perform insertion sort on Array
void InsertionSort(int Array[], int Size) {
    for (int i = 1; i < Size; i++) {                // Start from second element (first element is considered sorted)
        int Key = Array[i];                         // Current element to insert into sorted left portion
        int j = i - 1;                              // Index of last element in sorted portion will be used as comparison starting point
    
        while (j >= 0 && Array[j] > Key) {          // Shift elements greater than Key to the right
            Array[j + 1] = Array[j];                // Shift element right to make space for the key which will be inserted later
            j--;                                    // Move left through sorted portion
        }
        Array[j + 1] = Key;                         // Insert Key into its correct sorted position
    }
}

int BinarySearch(int* Array, int Value, int Size) {
    int LB = 0;                             // Initialize lower bound
    int HB = Size - 1;                      // Initialize higher bound
    
    while (LB <= HB) {                      // Continue while search space exists
        int Mid = LB + (HB - LB) / 2;       // Calculate middle index (avoids overflow)
        if (Array[Mid] == Value) {          // Check if value is at MID
            return Mid;                     // Value FOUND at mid index
        } else if (Array[Mid] < Value) {    // If value is greater than mid
            LB = Mid + 1;                   // Search in the right half
        } else {                            // If value is smaller than mid
            HB = Mid - 1;                   // Search in the left half
        }
    }
    return -1;  // Value NOT FOUND in array
}

int main() {
    cout << "=== Insertion Sort and Binary Search ===" << endl;
    int Size, Value;
    int Array[Size];
    cout << "Enter the No.of Elements(Size): ";
    cin >> Size;
    cout << "Enter the Element Value: ";
    for(int i = 0; i < Size; i++){
        cin >> Array[i];
    }
    // Display Original Array and Sorted Array
    cout << endl;
    PrintArray(Array, Size, "Before Insertion Sort: {");
    InsertionSort(Array, Size);
    PrintArray(Array, Size, "After Insertion Sort: {");

    // Search for Value Using Binary Search
    cout << "\nEnter Value to be Searched: ";
    cin >> Value;
    int Result = BinarySearch(Array, Value, Size);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index(1-10): " << Result << endl;
    return 0;
}
