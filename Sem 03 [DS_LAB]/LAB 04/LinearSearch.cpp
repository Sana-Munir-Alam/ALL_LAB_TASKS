#include <iostream>
using namespace std;

int LinearSearch(int* Array, int Value, int Size) {
    for (int i = 0; i < Size; i++) {        // Iterate through each element in array
        if (Array[i] == Value) {            // Check if current element matches search value
            return i;                       // Value FOUND at current index
        }
    }
    return -1;                              // Value NOT FOUND in array
}

int main() {
    int Array[5] = {2, 3, 4, 10, 40};      // Array for linear search (doesn't need to be sorted)
    int Size = 5;                           // Size of the array
    int Value1 = 10;                        // First value to search for (exists in array)
    int Value2 = 76;                        // Second value to search for (not in array)
    
    // Print the array
    cout << "Array: {";
    for (int i = 0; i < Size; i++) {
        cout << Array[i];
        if (i < Size - 1) cout << ", ";
    }
    
    // Search for first value
    cout << "}\n\nFirst Value to be Searched: " << Value1 << endl;
    int Result = LinearSearch(Array, Value1, Size);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index: " << Result << endl;
    
    // Search for second value
    cout << "\nSecond Value to be Searched: " << Value2 << endl;
    Result = LinearSearch(Array, Value2, Size);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index: " << Result << endl;
    
    return 0;
}
