#include <iostream>
using namespace std;

// Direct Recursion Example
int Factorial (int n){
    // Base Case [Terminates more recursive call]
    if(n==0){ cout << "\n"; return 1; }
    // General Case:
    cout << n;
    if (n!=1){ cout << "*";}   // Simply Prints *
    // Recursive Call
    return n * Factorial(n-1);      // N*(N-1)
}

// Indirect Recursion Example: When a Function A calls a Function B which recalls A. and the pattern repeats until base case is met PROTOTYPING IS MUST HERE
int FunctionA(int n);
int FunctionB(int n);
// Basically the two functions are like playing throwball, calling eachother one at a time with values being passed and changed.
int FunctionA(int n){
    if (n > 0){
        cout << n << " A ";
        return FunctionB(n-1);
    }
    return 0;
}

int FunctionB(int n){
    if (n>1){
        cout << n << " B ";
        return FunctionA(n/2);
    }
    return 0;
}

// NESTED Recursion
int FunctionNested(int n){
    // Base Case [Terminates more recursive call]
    if(n > 100){
        cout << n << " IF ";
        return n-10; 
    } else{
        cout << n << " ELSE ";
        return FunctionNested(FunctionNested(n+11));
    }
}
int main(){
    int Value = 5;
    int Result;
    cout << "\n\n=======DIRECT RECURSION=======\n";
    Result = Factorial(5);
    cout << "\nFactorial of " << Value << ": " << Result;
    cout << "\n\n=======INDIRECT RECURSION=======\n";
    cout << FunctionA(20);
    cout << "\n\n=======NESTED RECURSION=======\n";
    Result = FunctionNested(97);
    cout << "\nNESTED of " << Value << ": " << Result;
    return 0;
}
