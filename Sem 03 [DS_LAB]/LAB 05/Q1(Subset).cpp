#include <iostream>
using namespace std;

// Recursive function to find subsets that sum to target
bool isSubsetSum(int arr[], int size, int target, int subset[], int subsetSize) {
    if (target == 0) {                          // Base case: if target becomes 0, print the subset
        cout << "[ ";
        for (int i = 0; i < subsetSize; i++){ cout << subset[i] << " "; }
        cout << "]" << endl;
        return true;                            // Found at least one valid subset
    }

    // Base case: no elements left
    if (size == 0 && target != 0){ return false; }
    bool found = false;

    if (arr[size - 1] <= target) {              // Include current element (if it doesn’t exceed target)
        subset[subsetSize] = arr[size - 1];
        found = isSubsetSum(arr, size - 1, target - arr[size - 1], subset, subsetSize + 1) || found;
    }
    // Exclude current element
    found = isSubsetSum(arr, size - 1, target, subset, subsetSize) || found;

    return found;
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    int subset[50]; // Temporary array to hold subset elements

    cout << "Input: arr = [3, 34, 4, 12, 5, 2], target = 9" << endl;
    cout << "Subsets that sum to " << target << ":" << endl;

    bool result = isSubsetSum(arr, size, target, subset, 0);
    cout << "Result: " << (result ? "True" : "False (no subset found)") << endl;

    return 0;
}
