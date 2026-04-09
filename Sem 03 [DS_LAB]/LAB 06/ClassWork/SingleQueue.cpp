#include <iostream>
using namespace std;

class SingleQueue {
private:
    int *arr;       // Array to store queue elements.
    int capacity;   // Maximum number of elements the queue can hold.
    int size;       // Current number of elements in the queue.

public:
    SingleQueue(int c) {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    // Check if the queue is full
    bool isFull() { return size == capacity; }

    // Check if the queue is empty
    bool isEmpty() { return size == 0; }

    // Insert element in the queue
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Error: OVERFLOW!! Queue is FULL!" << endl;
            return;
        }
        arr[size] = element;    // Store element in empty space
        size++;                 // Move one index forward    
        cout << "Inserted: " << element << endl;
    }

    // Delete element from the queue
    void Dequeue() {
        if (isEmpty()) {
            cout << "Error: UNDERFLOW!! Queue is EMPTY!" << endl;
            return;
        }
        cout << "Removed: " << arr[0] << endl;
        for (int i = 1; i < size; i++){
            
            arr[i - 1] = arr[i];    // SHift the queue forward to cover the empty space
        }
        size--;    
    }

    // Display elements of queue
    void Display() {
        if (isEmpty()) {
            cout << "Error: UNDERFLOW!! Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Returns the front element of the queue.
    int getFront(){
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return -1;
        }
        return arr[0];
    }
    // Return the last element of queue
    int getRear(){
        if (isEmpty()) {
            cout << "Error:  Queue is EMPTY!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

int main() {
    SingleQueue q(5);

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
