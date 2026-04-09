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
