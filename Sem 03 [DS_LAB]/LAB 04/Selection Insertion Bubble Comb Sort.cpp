#include <iostream>
using namespace std;

// Function to find and return the minimum value in an Array
int FindMinValue(int Array[], int Size) {
    int Min = Array[0];                 // Initialize with first element
    for (int i = 1; i < Size; i++) {    // Iterate through Array to find minimum value
        if (Array[i] < Min) {           // Check if Current Value is smaller than Minimum Value
            Min = Array[i];             // Update Min if smaller element found
        }
    }
    return Min;
}

// Function to perform selection sort on Array
void SelectionSort(int Array[], int Size) {
    for (int i = 0; i < Size - 1; i++) {            // Outer loop for each position in Array
        int MinIndex = i;                           // Assuming current position has minimum value
        for (int j = i + 1; j < Size; j++) {        // Inner loop to find actual minimum in unsorted portion
            if (Array[j] < Array[MinIndex]) {       // Check if Current Value is smaller than Minimum Value
                MinIndex = j;                       // Update index of minimum value
            }
        }
        // Swap current element with minimum found
        // Method I of Swapping: 
        swap(Array[i], Array[MinIndex]);
        // Method II of Swapping
        // int Temp = Array[i];
        // Array[i] = Array[MinIndex];
        // Array[MinIndex] = Temp;
    }
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

// Function to perform comb sort on Array
void CombSort(int Array[], int Size) {
    int gap = Size;           // Initialize gap to the full array size
    bool swapped = true;      // Flag to track if any swaps occurred in the last pass
    
    // Continue sorting until gap becomes 1 AND no swaps occurred (array is sorted)
    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;   // Reduce the gap using the shrink factor (approximately 1.3)
        if (gap < 1) gap = 1;    // Ensure gap never goes below 1 (like bubble sort)
        swapped = false;         // Reset swap flag for this pass
        
        // Perform a single pass through the array with the current gap
        for (int i = 0; i + gap < Size; i++) {
            if (Array[i] > Array[i + gap]) {        // Compare elements that are 'gap' distance apart
                swap(Array[i], Array[i + gap]);     // Swap elements if they're in the wrong order
                swapped = true;                     // Set flag indicating a swap occurred
            }
        }
    }
}


// Function to print Array elements
void PrintArray(int Array[], int Size, string message = "Array: ") {
    cout << message;
    for (int i = 0; i < Size; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int main() {
    int Array[10] = {14, 12, 1, 4, 2, 4, 5, 21, 17, 6};
    int SelectionArray[10] = {21, 13, 14, 7, 18, 25, 32, 12, 17, 10};
    int InsertionArray[10] = {32, 5, 15, 0, 34, 11, 25, 8, 12, 1};
    int BubbleArray[10] = {45, 23, 9, 18, 3, 29, 14, 7, 31, 2};
    int CombArray[10] = {12, 34, 54, 2, 3, 78, 23, 9, 45, 11};
    int Size = 10;
    
    // Display original Array
    PrintArray(Array, Size, "Original Array: ");
    
    // Find and display minimum value
    int Minue = FindMinValue(Array, Size);
    cout << "Minimum Value: " << Minue << endl << endl;
    
    // Perform and display selection sort
    cout << "=== SELECTION SORT ===" << endl;
    PrintArray(SelectionArray, Size, "Before Selection Sort: ");
    SelectionSort(SelectionArray, Size);
    PrintArray(SelectionArray, Size, "After Selection Sort: ");
    
    cout << endl;
    
    // Perform and display insertion sort
    cout << "=== INSERTION SORT ===" << endl;
    PrintArray(InsertionArray, Size, "Before Insertion Sort: ");
    InsertionSort(InsertionArray, Size);
    PrintArray(InsertionArray, Size, "After Insertion Sort: ");
    
    cout << endl;

    // Perform and display bubble sort
    cout << "=== BUBBLE SORT ===" << endl;
    PrintArray(BubbleArray, Size, "Before Bubble Sort: ");
    BubbleSort(BubbleArray, Size);
    PrintArray(BubbleArray, Size, "After Bubble Sort: ");
    
    // Perform and display comb sort
    cout << "=== COMB SORT ===" << endl;
    PrintArray(CombArray, Size, "Before Comb Sort: ");
    CombSort(CombArray, Size);
    PrintArray(CombArray, Size, "After Comb Sort: ");
    return 0;
}
