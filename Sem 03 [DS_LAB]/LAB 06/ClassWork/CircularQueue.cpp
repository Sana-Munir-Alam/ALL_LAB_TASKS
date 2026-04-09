#include <iostream>
using namespace std;

#define SIZE 5          // maximum size of the circular queue

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;     // Initial Position of Front Pointer (pop from here)
        rear = -1;      // Initial Position of Rear Pointer (push from here)
    }

    // Check if the queue is full
    bool isFull() {
        // If push pointer is at end of array and pop pointer is at 0, or the pop pointer has crossed pop pointer. (front > rear)
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)){
            return true;
        }
        return false;
    }

    // Check if the queue is empty
    bool isEmpty() { return (front == -1); }    // Push pointer is -1 means empty queue

    // Insert element in the queue
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Error: OVERFLOW!! Queue is FULL!" << endl;
            return;
        }
        if (front == -1 && rear == -1) {front = 0;}   // First element
        rear = (rear + 1) % SIZE;                     // Move Push pointer one step forward using MOD size in order to wrap around when size of array exceeded
        items[rear] = element;                        // Store element pointed by rear
        cout << "Inserted: " << element << endl;
    }

    // Delete element from the queue
    void Dequeue() {
        if (isEmpty()) {
            cout << "Error: UNDERFLOW!! Queue is EMPTY!" << endl;
            return;
        }
        cout << "Removed: " << items[front] << endl;
        if (front == rear) {            // Queue has only one element
            front = -1;                 // Reset front pointer
            rear = -1;                  // reset rear pointer
        } else {
            front = (front + 1) % SIZE; // Move pop pointer one step forward and wrap if it exceeds capacity
        }
    }

    // Display elements of queue
    void Display() {
        if (isEmpty()) {
            cout << "Error: UNDERFLOW!! Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);

    q.Display();

    q.Dequeue();
    q.Dequeue();

    q.Display();

    q.Enqueue(60);
    q.Enqueue(70);

    q.Display();
    q.Enqueue(25);  // Overflow error as capcity exceeds 5
    q.Display();

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();
    q.Dequeue();    // Underflow error as queue is empty and we are dequeing from nothing
    q.Display();

    return 0;
}
