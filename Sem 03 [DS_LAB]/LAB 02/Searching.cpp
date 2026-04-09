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
















#include <iostream>
using namespace std;

/*
Interpolation search is a searching technique used on sorted and uniformly distributed arrays. 
It is similar to binary search, but instead of always checking the middle element, it tries to 
guess the position of the required value based on how far it is from the first and last values 
of the array. This makes it faster when the data is evenly spread out.
The formula estimates where the value might be, instead of just dividing the array in half.
Eg of How Interpolation Formula work:
Suppose we want to search for 18 in this array:
[10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]    => It is an unifromed distributed array
First, we apply the formula and get position 3, which has 16. Since 16 < 18, we move to the right part.
In the next calculation, we directly land at position 4, which is 18. So, the value is found.
*/

int InterpolationSearch(int Array[], int Size, int Value) {
    int Low = 0;                    // Initialize lower bound
    int High = Size - 1;            // Initialize upper bound
    
    while (Low <= High && Value >= Array[Low] && Value <= Array[High]) {    // Continue while search space is valid and value is within array bounds
        if (Low == High) {                              // Handle case when search space reduces to single element
            if (Array[Low] == Value) { return Low; }    // Value found at Low index
            return -1;                                  // Value not found
        }
        // Calculate position using interpolation formula (This calculates: "If values are evenly distributed, where should this value be located?")
        int pos = Low + ((Value - Array[Low]) * (High - Low)) / (Array[High] - Array[Low]);
        /*
        (Value - Array[Low]) - How far the value is from the smallest element
        (High - Low) - The total index range
        (Array[High] - Array[Low]) - The total range of values
        */
        
        // Check if value is found at calculated position
        if (Array[pos] == Value) {
            return pos;                     // Value found at calculated position
        } else if (Array[pos] < Value) {    // If value is greater than element at pos
            Low = pos + 1;                  // Search in the upper part (RHS)
        } else {                            // If value is smaller than element at pos
            High = pos - 1;                 // Search in the lower part (LHS)
        }
    }
    return -1;  // Value not found in array
}

int main() {
    // Sorted array for interpolation search (should be uniformly distributed)
    int Array[15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
    int Size = 15;    
    int Value1 = 70;  // Element to be searched (exists in array)
    int Value2 = 67;  // Element to be searched (does not exist in array)
    
    // Print the array
    cout << "Array: {";
    for (int i = 0; i < Size; i++) {
        cout << Array[i];
        if (i < Size - 1) cout << ", ";
    }
    
    // Search for first value
    cout << "}\n\nFirst Value to be Searched: " << Value1 << endl;
    int Result = InterpolationSearch(Array, Size, Value1);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index: " << Result << endl;
    
    // Search for second value
    cout << "\nSecond Value to be Searched: " << Value2 << endl;
    Result = InterpolationSearch(Array, Size, Value2);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index: " << Result << endl;
    
    return 0;
}





















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