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
// Function to perform bubble sort on Array
void BubbleSort(int Array[], int Size) {
    // Outer loop: controls number of passes through the array
    for (int i = 0; i < Size - 1; i++) {
        // Inner loop: compares adjacent elements and swaps if needed. After each pass, the largest element moves to its correct position
        for (int j = 0; j < Size - i - 1; j++) {    // The (Size - i - 1) ensures we don't check already sorted elements
            if (Array[j] > Array[j + 1]) {          // Compare adjacent elements
                swap(Array[j], Array[j + 1]);       // Swap elements if they're in the wrong order
            }
        }
    }
}
// Function to Perform Linaer Search
int LinearSearch(int* Array, int Size, int Value ) {
    for (int i = 0; i < Size; i++) {        // Iterate through each element in array
        if (Array[i] == Value) {            // Check if current element matches search value
            return i;                       // Value FOUND at current index
        }
    }
    return -1;                              // Value NOT FOUND in array
}

int main() {
    cout << "\n=== Bubble Sort and Linear Search ===" << endl;
    int Size, Value;
    int Array[Size];
    cout << "Enter the No.of Elements(Size): ";
    cin >> Size;
    cout << "Enter the Element Value(uniformly distributed): ";
    for(int i = 0; i < Size; i++){
        cin >> Array[i];
    }

    // Display Original Array and Sorted Array
    cout << endl;
    PrintArray(Array, Size, "Before Bubble Sort: {");
    BubbleSort(Array, Size);
    PrintArray(Array, Size, "After Bubble Sort: {");

    // Search for Value Using Linear Search
    cout << "\nEnter Value to be Searched: ";
    cin >> Value;
    int Result = LinearSearch(Array, Size, Value);
    (Result == -1) ? cout << "Element is not present in Array\n" : cout << "Element Found at Index(1-10): " << Result << endl;

    return 0;
}
