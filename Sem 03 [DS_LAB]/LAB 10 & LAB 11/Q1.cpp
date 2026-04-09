#include <iostream>
#include <cstring>

using namespace std;

struct Incident {
    int severity;
    int timestamp;
    char description[100];
};

class PriorityQueue {
private:
    Incident* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            
            // Compare severity first, then timestamp if severity is equal
            if (heap[parent].severity < heap[index].severity || (heap[parent].severity == heap[index].severity && heap[parent].timestamp > heap[index].timestamp)) {
                swap(heap[parent], heap[index]);
                index = parent;
            } 
            else { break; }
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size) {
                if (heap[left].severity > heap[largest].severity || (heap[left].severity == heap[largest].severity && heap[left].timestamp < heap[largest].timestamp)) {
                    largest = left;
                }
            }

            if (right < size) {
                if (heap[right].severity > heap[largest].severity || (heap[right].severity == heap[largest].severity && heap[right].timestamp < heap[largest].timestamp)) {
                    largest = right;
                }
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue(int cap = 100) {
        capacity = cap;
        size = 0;
        heap = new Incident[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void addIncident(int severity, int timestamp, const char* desc) {
        if (size >= capacity) {
            // Resize if needed
            capacity *= 2;
            Incident* newHeap = new Incident[capacity];
            for (int i = 0; i < size; i++) {
                newHeap[i] = heap[i];
            }
            delete[] heap;
            heap = newHeap;
        }

        heap[size].severity = severity;
        heap[size].timestamp = timestamp;
        strcpy(heap[size].description, desc);
        
        heapifyUp(size);
        size++;
    }

    bool dispatch() {
        if (size == 0) {
            cout << "NO INCIDENTS" << endl;
            return false;
        }

        // Print the highest priority incident
        cout << "DISPATCHED: Severity " << heap[0].severity << ", Time " << heap[0].timestamp << ", \"" << heap[0].description << "\"" << endl;

        // Remove from heap
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return true;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;
    char command[10];
    int severity, timestamp;
    char description[100];

    cout << "Emergency Response System" << endl;
    cout << "Commands: ADD <severity> <timestamp> <description>" << endl;
    cout << "          DISPATCH" << endl;
    cout << "          EXIT" << endl;
    cout << "Example: ADD 5 100 Fire reported" << endl << endl;

    while (true) {
        cout << "> ";
        cin >> command;

        if (strcmp(command, "ADD") == 0) {
            cin >> severity >> timestamp;
            cin.ignore(); // Ignore newline
            cin.getline(description, 100);
            pq.addIncident(severity, timestamp, description);
            cout << "Incident added successfully." << endl;
        }
        else if (strcmp(command, "DISPATCH") == 0) {
            pq.dispatch();
        }
        else if (strcmp(command, "EXIT") == 0) {
            break;
        }
        else {
            cout << "Invalid command. Use ADD, DISPATCH, or EXIT." << endl;
        }
    }

    return 0;
}
