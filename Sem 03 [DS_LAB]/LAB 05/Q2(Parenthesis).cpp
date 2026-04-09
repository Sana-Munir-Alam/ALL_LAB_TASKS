#include <iostream>
using namespace std;

// Recursive function to generate parentheses
void generateParentheses(char str[], int pos, int n, int open, int close) {
    // If the current position equals 2*n, we have a valid combination
    if (pos == 2 * n) {
        str[pos] = '\0';        // Null terminate string
        cout << str << " ";     // Print valid combination
        return;
    }

    // If we can still add '(', add it and recurse
    if (open < n) {
        str[pos] = '(';
        generateParentheses(str, pos + 1, n, open + 1, close);
    }

    // If we can add ')', only add if there are more '(' used already
    if (close < open) {
        str[pos] = ')';
        generateParentheses(str, pos + 1, n, open, close + 1);
    }
}

int main() {
    int n = 3;
    char str[100]; // To store combinations

    cout << "Input: n = 3" << endl;
    cout << "Output: [";

    generateParentheses(str, 0, n, 0, 0);

    cout << "]" << endl;
    return 0;
}
