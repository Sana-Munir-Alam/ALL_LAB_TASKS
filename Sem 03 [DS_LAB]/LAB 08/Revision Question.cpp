#include <iostream>
using namespace std;

class CustomStack {
private:
    int* arr;
    int capacity;
    int topIndex;
    int totalInserted;

public:
    CustomStack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
        totalInserted = 0;
    }

    ~CustomStack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(int value) {
        if (topIndex == capacity - 1) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i <= topIndex; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[++topIndex] = value;
        totalInserted++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        // Check parity of total inserted
        if (totalInserted % 2 == 1) {
            // Odd → LIFO behavior
            int val = arr[topIndex--];
            totalInserted--;
            return val;
        } 
        else {
            // Even → FIFO behavior (remove from bottom)
            // Create a temporary stack
            CustomStack temp(capacity);

            // Move everything except the bottom element
            while (topIndex > 0) {
                temp.push(arr[topIndex--]);
            }

            // Bottom element to remove
            int bottomVal = arr[topIndex--];

            // Move elements back
            while (!temp.isEmpty()) {
                arr[++topIndex] = temp.pop();
            }

            totalInserted--;
            return bottomVal;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getTotalInserted() const {
        return totalInserted;
    }
};

int main() {
    CustomStack st;

    cout << "Inserting 10, 20, 30:\n";
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    cout << "\nPopping (odd totalInserted → LIFO): " << st.pop() << endl;
    st.display();

    cout << "\nPopping (even totalInserted → FIFO): " << st.pop() << endl;
    st.display();

    cout << "\nPopping again (odd → LIFO): " << st.pop() << endl;
    st.display();

    cout << "\nInserting 1, 2, 3, 4:\n";
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();

    cout << "\nNow removing new stack values based on parity sequence:\n";
    while (!st.isEmpty()) {
        cout << "Removed: " << st.pop() << endl;
        st.display();
    }

    return 0;
}
