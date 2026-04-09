#include <iostream>
using namespace std;

class myStack {
    int *arr;       
    int capacity;   
    int top;        

public:
    myStack(int cap) {
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
    bool isEmpty() {
        return top == -1;
    }

    // check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    myStack st(4);

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
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n";

    return 0;
}
