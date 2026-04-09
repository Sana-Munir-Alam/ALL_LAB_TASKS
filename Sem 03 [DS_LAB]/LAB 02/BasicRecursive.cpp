#include <iostream>
#include <string>
using namespace std;

// 1. Factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) return 1;  // Base case: factorial of 0 or 1 is 1
    return n * factorial(n - 1);     // Recursive step: n! = n × (n-1)!
    /*
    HOW IT WORKS:
    factorial(5) calls factorial(4)
      factorial(4) calls factorial(3)
        factorial(3) calls factorial(2)
          factorial(2) calls factorial(1)
            factorial(1) returns 1 (base case)
          factorial(2) returns 2 × 1 = 2
        factorial(3) returns 3 × 2 = 6
      factorial(4) returns 4 × 6 = 24
    factorial(5) returns 5 × 24 = 120
    */
}

// 2. Fibonacci (n-th term)
int fibonacci(int n) {
    if (n == 0) return 0;            // Base case: F(0) = 0
    if (n == 1) return 1;            // Base case: F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive: F(n) = F(n-1) + F(n-2)
    /*
    HOW IT WORKS (for fibonacci(4)):
    fibonacci(4) calls fibonacci(3) and fibonacci(2)
      fibonacci(3) calls fibonacci(2) and fibonacci(1)
        fibonacci(2) calls fibonacci(1) and fibonacci(0)
          fibonacci(1) returns 1
          fibonacci(0) returns 0
        fibonacci(2) returns 1 + 0 = 1
        fibonacci(1) returns 1
      fibonacci(3) returns 1 + 1 = 2
      fibonacci(2) calls fibonacci(1) and fibonacci(0)
        fibonacci(1) returns 1
        fibonacci(0) returns 0
      fibonacci(2) returns 1 + 0 = 1
    fibonacci(4) returns 2 + 1 = 3
    
    Note: This creates a binary recursion tree with exponential time complexity
    */
}

// 3. Sum of digits of a number
int sumOfDigits(int n) {
    if (n == 0) return 0;            // Base case: sum of digits of 0 is 0
    return (n % 10) + sumOfDigits(n / 10);  // Recursive: last digit + sum of remaining digits
    /*
    HOW IT WORKS (for 123):
    sumOfDigits(123) calls sumOfDigits(12)
      sumOfDigits(12) calls sumOfDigits(1)
        sumOfDigits(1) calls sumOfDigits(0)
          sumOfDigits(0) returns 0 (base case)
        sumOfDigits(1) returns 1 + 0 = 1
      sumOfDigits(12) returns 2 + 1 = 3
    sumOfDigits(123) returns 3 + 3 = 6
    */
}

// 4. Reverse a string
void reverseString(string &s, int start, int end) {
    if (start >= end) return;        // Base case: pointers have met or crossed
    swap(s[start], s[end]);          // Swap characters at start and end positions
    reverseString(s, start + 1, end - 1);  // Recursive: move pointers inward
    /*
    HOW IT WORKS (for "hello", start=0, end=4):
    First call: swap 'h' and 'o' → "oellh", call with start=1, end=3
      Second call: swap 'e' and 'l' → "olleh", call with start=2, end=2
        Third call: start >= end, return (base case)
    Final result: "olleh"
    */
}

// 5. Print numbers from 1 to N (ascending order)
void print1ToN(int n) {
    if (n == 0) return;              // Base case: nothing to print
    print1ToN(n - 1);                // Recursive: print numbers 1 to (n-1) first
    cout << n << " ";                // Then print current number
    /*
    HOW IT WORKS (for n=3):
    print1ToN(3) calls print1ToN(2)
      print1ToN(2) calls print1ToN(1)
        print1ToN(1) calls print1ToN(0)
          print1ToN(0) returns (base case)
        print1ToN(1) prints "1 "
      print1ToN(2) prints "2 "
    print1ToN(3) prints "3 "
    Output: "1 2 3 "
    
    This uses "head recursion" - the recursive call happens BEFORE the action
    */
}

// Print numbers from N to 1 (descending order)
void printNTo1(int n) {
    if (n == 0) return;              // Base case: nothing to print
    cout << n << " ";                // Print current number first
    printNTo1(n - 1);                // Recursive: then print numbers (n-1) to 1
    /*
    HOW IT WORKS (for n=3):
    printNTo1(3) prints "3 ", then calls printNTo1(2)
      printNTo1(2) prints "2 ", then calls printNTo1(1)
        printNTo1(1) prints "1 ", then calls printNTo1(0)
          printNTo1(0) returns (base case)
    Output: "3 2 1 "
    
    This uses "tail recursion" - the recursive call happens AFTER the action
    */
}

// 6. Find Maximum in Array
int findMax(int arr[], int n) {
    if (n == 1) return arr[0];       // Base case: array of size 1, max is the only element
    return max(arr[n - 1], findMax(arr, n - 1));  // Recursive: max of last element vs max of rest
    /*
    HOW IT WORKS (for [3, 1, 4, 2]):
    findMax(arr, 4) compares arr[3]=2 with findMax(arr, 3)
      findMax(arr, 3) compares arr[2]=4 with findMax(arr, 2)
        findMax(arr, 2) compares arr[1]=1 with findMax(arr, 1)
          findMax(arr, 1) returns arr[0]=3 (base case)
        findMax(arr, 2) returns max(1, 3) = 3
      findMax(arr, 3) returns max(4, 3) = 4
    findMax(arr, 4) returns max(2, 4) = 4
    */
}

// Find Minimum in Array
int findMin(int arr[], int n) {
    if (n == 1) return arr[0];       // Base case: array of size 1, min is the only element
    return min(arr[n - 1], findMin(arr, n - 1));  // Recursive: min of last element vs min of rest
    /*
    HOW IT WORKS (similar to findMax but using min instead of max)
    */
}

// ===== MAIN FUNCTION =====
int main() {
    // Test all the recursive functions
    cout << "Factorial of 5: " << factorial(5) << endl;

    cout << "First 10 Fibonacci numbers: ";
    for (int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    int num = 12345;
    cout << "Sum of digits of " << num << ": " << sumOfDigits(num) << endl;

    string str = "recursion";
    reverseString(str, 0, str.size() - 1);
    cout << "Reversed string: " << str << endl;

    cout << "Numbers from 1 to 10: ";
    print1ToN(10);
    cout << endl;

    cout << "Numbers from 10 to 1: ";
    printNTo1(10);
    cout << endl;

    int arr[6] = {12, 5, 34, 7, 89, 2};
    cout << "Maximum value in array: " << findMax(arr, 6) << endl;
    cout << "Minimum value in array: " << findMin(arr, 6) << endl;

    return 0;
}