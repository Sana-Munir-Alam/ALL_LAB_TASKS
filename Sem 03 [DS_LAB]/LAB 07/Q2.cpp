#include <iostream>
#include <string>

using namespace std;

class Review {
    private:
        int Rating;
        string Text;

    public:
        // Constructor
        Review(int r = 0, string t = "") : Rating(r), Text(t) {}
        
        // Getter methods
        int GetRating() const { return Rating; }
        string GetText() const { return Text; }
        
        // Setter methods
        void SetRating(int r) { Rating = r; }
        void SetText(string t) { Text = t; }
        
        // Comparison method for sorting
        bool ShouldComeBefore(const Review& other) const {
            // Sort by descending Rating first
            if (Rating > other.Rating) return true;
            if (Rating < other.Rating) return false;
            
            // If Ratings are equal, sort alphabetically by Text
            return Text < other.Text;
        }
        
        // Display method
        void Display() const {
            cout << "Rating: " << Rating << ", Review: \"" << Text << "\"";
        }
};

// Merge function for Merge Sort
void Merge(Review Array[], int Left, int Mid, int Right) {
    int n1 = Mid - Left + 1;    // Lower Array size
    int n2 = Right - Mid;       // Upper Array size
    
    // Create temporary Arrays
    Review* LeftArray = new Review[n1];
    Review* RightArray = new Review[n2];
    
    // Copy data to temporary Arrays
    for (int i = 0; i < n1; i++)
        LeftArray[i] = Array[Left + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = Array[Mid + 1 + j];
    
    // Merge the temporary Arrays back into Array[Left..Right]
    int i = 0, j = 0, k = Left;
    while (i < n1 && j < n2) {
        if (LeftArray[i].ShouldComeBefore(RightArray[j])) {
            Array[k] = LeftArray[i];
            i++;
        } else {
            Array[k] = RightArray[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of LeftArray if any
    while (i < n1) {
        Array[k] = LeftArray[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of RightArray if any
    while (j < n2) {
        Array[k] = RightArray[j];
        j++;
        k++;
    }
    
    // Free temporary Arrays
    delete[] LeftArray;
    delete[] RightArray;
}

// Merge Sort function
void MergeSort(Review Array[], int Left, int Right) {
    if (Left >= Right) return;
    int Mid = Left + (Right - Left) / 2;
    
    // Sort first and second halves
    MergeSort(Array, Left, Mid);
    MergeSort(Array, Mid + 1, Right);
    
    Merge(Array, Left, Mid, Right); // Merge the sorted halves
}

// Function to print the sorted reviews
void PrintReviews(Review Array[], int size) {
    for (int i = 0; i < size; i++) {
        Array[i].Display();
        cout << endl;
    }
}

int main() {
    // Example usage
    const int SIZE = 8;
    Review reviews[SIZE];
    
    // Initialize reviews
    reviews[0] = Review(5, "Excellent product!");
    reviews[1] = Review(3, "It's okay");
    reviews[2] = Review(5, "Amazing quality");
    reviews[3] = Review(2, "Not good");
    reviews[4] = Review(4, "Very good");
    reviews[5] = Review(3, "Average product");
    reviews[6] = Review(5, "Best purchase ever");
    reviews[7] = Review(4, "Great value for money");
    
    cout << "Original reviews:" << endl;
    PrintReviews(reviews, SIZE);
    
    // Sort the reviews
    MergeSort(reviews, 0, SIZE - 1);
    
    cout << "\nSorted reviews (by descending Rating, then alphabetically):" << endl;
    PrintReviews(reviews, SIZE);
    
    return 0;
}
