#include <iostream>
using namespace std;

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
    int Array[5] = {2, 3, 4, 10, 40};   // Sorted array for binary search
    int Size = 5;                       // Size of the array
    int Value1 = 10;                    // First value to search for (exist in array)
    int Value2 = 76;                    // Second value to search for (not in array)
    
    // Print the array
    cout << "Array: {";
    for (int i = 0; i < Size; i++) {
        cout << Array[i];
        if (i < Size - 1) cout << ", ";
    }
    
    // Search for first value
    cout << "}\n\nFirst Value to be Searched: " << Value1 << endl;
    int Result = BinarySearch(Array, Value1, Size);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index: " << Result << endl;
    
    // Search for second value
    cout << "\nSecond Value to be Searched: " << Value2 << endl;
    Result = BinarySearch(Array, Value2, Size);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index: " << Result << endl;
    
    return 0;
}
