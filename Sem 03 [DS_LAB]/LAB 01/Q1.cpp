#include <iostream>
using namespace std;

class BankAccount{
    private:
    int Balance; // For simplicty i am going with balance being an integr and not float.
    public:
        BankAccount(){                                              // Default Constructor as it has no paramter being passed.
            Balance = 0;                                            // Initialising Balance as $0 with the assumption that this is default cpnstructor so the account will have 0 dollar.
            cout << "Default Constructor at Work" << endl;          // Check if default constructor work as needed
        }
        BankAccount(int InitialBal){                                // Parameterized  Constructor as it has a parameter
            Balance = InitialBal;                                   // Storing an Initial Balance inside the variable
            cout << "Parameterized  Constructor at Work" << endl;   // Check if paramtrized constructor work as needed.
        }
        BankAccount(const BankAccount& other){                      // Copy Constrcutor
            Balance = other.Balance;                                // Copying the balcne of another account in a new account balance
            cout << "Copy Constructor called!" << endl;             // Check if Copy Constructor work as intended
        }
        void Withdraw(int Value){                                   // A function that deducts money from Balance incase a user wants to withraw money from thier account
            if (Value <= Balance && Value >=0){                     // Check so that a valid amount can only be withdrawn
                Balance = Balance - Value;                          // Deducting Money;
                // Printing a status after a successful withdrawl
                cout << "Amount $" << Value << " deducted successfully!\nYour Current Balance is: $" << Balance << endl;
            } else if(Value > Balance){         // Will run when Amount is greater than Balance to print an error message
                cerr << "Error: Insufficent Balance. Therefore Can not withdraw money." << endl;    // using cerr cause it's used to print error.
            } else {                            // Will run when the value entered is either negative or wrong for the condition check hence will print an error message
                cerr << "Error: Invalid Value entered. Sorry there was a trouble withdrawing money. Ensure you have entered a valid amount to be withdrawn" << endl;
            }
        }
        int getBalance() const {    // A function that will return a balance, using const so that no accidental changes are made to the Balance when returning.
            return Balance;
        }
};

int main(){
    cout << "Sana Munir Alam 24K-0573\n\n";
    BankAccount Acc1;           // Will call default constructor
    cout << "Account 1 Balance: $" << Acc1.getBalance() << endl << endl;
    BankAccount Acc2(1000);     // Will call parameterized  Constructor with initial $1000 balance.
    cout << "Account 2 Balance: $" << Acc2.getBalance() << endl << endl;

    BankAccount Acc3(Acc2);    // Will Call Copy Constructor
    cout << "Account 3 Balance just after Copying: $" << Acc3.getBalance() << endl;         // Will Show $1000 intially
    Acc3.Withdraw(200);        // Withdrawing $200 from Account 3
    cout << "Account 3 Balance after Withdrawing: $" << Acc3.getBalance() << endl;          // Will Show $800.
    cout << "Account 2 Balancee [will remain unchanged]: $" << Acc2.getBalance() << endl;   // Will Show $1000 as it should.
    return 0;
}