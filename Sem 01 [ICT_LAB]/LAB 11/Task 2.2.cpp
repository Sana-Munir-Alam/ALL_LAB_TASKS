#include <iostream>
#include <string>
using namespace std;

class Account {
    protected:
        string AccountNumber;
        string AccountHolderName;
        double Balance;
    public:
        // Constructor to initialize account number and holder's name
        Account(string AccNumber, string AccHolder) : AccountNumber(AccNumber), AccountHolderName(AccHolder), Balance(0.0) {}

        // Method (Deposit)
        void Deposit(double Amount) {
            Balance += Amount;
            cout << "Deposited: $" << Amount << endl;
        }
        // Method (Withdraw)
        virtual void Withdraw(double Amount) {
            if (Amount <= Balance) {
                Balance -= Amount;
                cout << "Withdrew: $" << Amount << endl;
            } else {
                cout << "Insufficient Balance!!" << endl;
            }
        }
        // Method (Check Balance)
        void CheckBalance() const {
            cout << "Account Balance: $" << Balance << endl;
        }
};

// SavingsAccount class derived from Account
class SavingsAccount : public Account {
    private:
        double InterestRate;
    public:
        // Constructor to initialize Savings Account with Interest Rate
        SavingsAccount(string AccNumber, string AccHolder, double intRate) : Account(AccNumber, AccHolder), InterestRate(intRate) {}

        // Method to calculate interest earned
        void CalculateInterest() {
            double interest = Balance * (InterestRate / 100);
            cout << "Interest Earned: $" << interest << endl;
            Deposit(interest);
        }
};
// CurrentAccount class derived from Account
class CurrentAccount : public Account {
    private:
        double OverdraftLimit;  // Overdraft limit for current account
    public:
        // Constructor to initialize Current Account with overdraft limit
        CurrentAccount(string AccNumber, string AccHolder, double overdraftLimit) : Account(AccNumber, AccHolder), OverdraftLimit(overdraftLimit) {}
        // Method (Override Withdraw)
        void Withdraw(double Amount) override {
            if (Amount <= Balance + OverdraftLimit) {
                Balance -= Amount;
                cout << "Withdrew: $" << Amount << endl;
            } else {
                cout << "Overdraft Limit Exceeded!!" << endl;
            }
        }
};

int main() {
    SavingsAccount savings("123456", "Colonel Brandon", 5.0);

    CurrentAccount current("654321", "Severus Snape", 500.0);
    cout << "Colonel Brandon: " << endl;
    savings.Deposit(1000.0);
    savings.Withdraw(200.0);
    savings.CalculateInterest();  // Calculate interest
    cout << endl;
    cout << "Severus Snape: " << endl;
    // Severus Snape
    current.Deposit(200.0);
    current.Withdraw(50.0);
    current.Withdraw(300.0);  // Overdraft allowed

    savings.CheckBalance();
    current.CheckBalance();

    return 0;
}
