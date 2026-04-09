#include <iostream>
#include <string>

using namespace std;

class Destination {
private:
    string Name;
    int ETA;

    public:
        // Parmaetrised Constructor
        Destination(string n = "", int e = 0) : Name(n), ETA(e) {}
        
        // Getter methods
        string GetName() const { return Name; }
        int GetETA() const { return ETA; }
        
        // Setter methods
        void SetName(string n) { Name = n; }
        void SetETA(int e) { ETA = e; }
        
        // Comparison operator for sorting logic
        bool ShouldComeBefore(const Destination& other) const {
            if (ETA < other.ETA) return true;                           // Compare Check of ETA first
            if (ETA == other.ETA && Name < other.Name) return true;     // Incase above fails than check for Alphabetically
            return false;
        }
        
        // Display method
        void Display() const {
            cout << "Destination: " << Name << ", ETA: " << ETA << " minutes";
        }
};

// Function to Swap two Destination objects
void Swap(Destination* a, Destination* b) {
    Destination temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quicksort
int Partition(Destination Array[], int Low, int High) {
    Destination pivot = Array[High];                // Choose the rightmost element as pivot
    int i = Low - 1;                                // Index of smaller element
    
    for (int j = Low; j < High; j++) {
        if (Array[j].ShouldComeBefore(pivot)) {     // Use the class method for comparison
            i++;                                    // Move smaller value index forward
            Swap(&Array[i], &Array[j]);             // Swao
        }
    }
    // Place pivot in correct position
    Swap(&Array[i + 1], &Array[High]);
    return i + 1;
}

// Quicksort function
void quickSort(Destination Array[], int Low, int High) {
    if (Low < High) {
        // Partition the Arrayay and get pivot index
        int pivotIndex = Partition(Array, Low, High);
        // Recursively sort elements before and after Partition
        quickSort(Array, Low, pivotIndex - 1);
        quickSort(Array, pivotIndex + 1, High);
    }
}

// Function to print the sorted destinations
void printDestinations(Destination Array[], int size) {
    for (int i = 0; i < size; i++) {
        Array[i].Display();
        cout << endl;
    }
}

int main() {
    const int SIZE = 6;
    Destination destinations[SIZE];
    
    // Initialize destinations
    destinations[0] = Destination("Store A", 120);
    destinations[1] = Destination("Customer B", 45);
    destinations[2] = Destination("Warehouse C", 90);
    destinations[3] = Destination("Customer A", 45);
    destinations[4] = Destination("Store B", 60);
    destinations[5] = Destination("Customer D", 90);
    
    cout << "Original destinations:" << endl;
    printDestinations(destinations, SIZE);
    // Sort the destinations
    quickSort(destinations, 0, SIZE - 1);
    
    cout << "\nSorted destinations (by ETA, then alphabetically):" << endl;
    printDestinations(destinations, SIZE);
    return 0;
}
