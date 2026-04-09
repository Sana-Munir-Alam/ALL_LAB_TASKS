#include <iostream>
using namespace std;

class LibraryBook{
    // As private
    int AvailableCopies;

    // As public
    public:
        string Title;
        string Author;
        long ISBN;

        // Member Functions
        void setCopies(int Copies){
            AvailableCopies = Copies;
        }

        int getCopies(){
            return AvailableCopies;
        }

        void displayDetails(){
            cout << " " << endl;
            cout << "Details Are: " << endl;
            cout << "Title: " << Title << endl;
            cout << "Author: " << Author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Available Copies: " << getCopies();
        }
};

int main(){
    int copies;
    LibraryBook Detail;

    cout << "Kindly enter the details" << endl;
    cout << "Enter Title: ";
    getline(cin, Detail.Title);
    cout << "Enter Author: ";
    getline(cin, Detail.Author);   
    cout << "Enter ISBN: ";
    cin >> Detail.ISBN;
    cout << "Available Copies: ";
    cin >> copies;

    Detail.setCopies(copies);
    Detail.displayDetails();
    return 0;
}