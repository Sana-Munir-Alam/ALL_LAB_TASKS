#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Stack {
    int *arr;       
    int capacity;   
    int top;        

public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    // push operation
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // peek (or top) operation
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // check if stack is empty
    bool isEmpty() { return top == -1; }

    // check if stack is full
    bool isFull() { return top == capacity - 1;}
};

int precedence(char c){
    if (c == '^'){
        return 3;
    } else if (c == '*' || c == '/'){
        return 2;
    } else if (c == '+' || c == '-'){
        return 1;
    } else {
        return -1;
    }
}
string InfixToPostfix (string infix) {
    string postfix = "";
    Stack s(infix.length());

    for (int i =0; i < infix.length(); i++){
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            postfix += c;           // if variables simply add it in postfix variable
        } else if (c == '('){
            s.push(c);              // if open bracket push it in stack
        } else if (c == ')'){       // if close bracket found
            while (!s.isEmpty() && s.peek() != '(') {   // loop until stack is either empty or we find another open bracket
                char op = s.pop();
                postfix += op;      // Add operand into postfix variable
            }
            if (s.peek() == '('){   // in case you find another open bracket inside another bracket
                s.pop();
            }
        } else {                    // If it's operators
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())){
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()){
        char op = s.pop();
        postfix += op;
    }
    return postfix;
}

int main() {
    Stack st(4);

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped: " << st.pop() << "\n";

    // checking top element
    cout << "Top element: " << st.peek() << "\n";

    st.pop(); // remove 3
    st.pop(); // remove 2
    st.pop(); // remove 1
    st.pop(); // underflow error
    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";

    st.push(1); // push 1
    st.push(2); // push 2
    st.push(3); // pus 3
    st.push(4); // push 4
    st.push(5); // push 5
    // checking if stack is full
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n\n\n";

    cout << "========= INFIX to POSTFIX =========\n";
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = InfixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
