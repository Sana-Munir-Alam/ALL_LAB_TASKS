#include <iostream>
using namespace std;

// Node class for Doubly Linked List elements
class DNode {
public:
    int data;        // Stores the actual value
    DNode* next;     // Pointer to the next node in the list
    DNode* prev;     // Pointer to the previous node in the list
    
    // Constructor to initialize node with value and set pointers to null
    DNode(int val) {
        data = val;
        next = prev = nullptr;  // New node initially points to nothing in both directions
    }
};

// Doubly Linked List class implementation
class DoublyLinkedList {
    DNode* head;  // Pointer to the first node in the list
    DNode* tail;  // Pointer to the last node in the list

public:
    // Constructor - initializes empty list
    DoublyLinkedList() {
        head = tail = nullptr;  // Both pointers null when list is empty
    }

    // Insert new node at the beginning of the list
    void insertAtStart(int val) {
        DNode* newNode = new DNode(val);  // Create new node with given value
        if (!head) {                      // If list is empty
            head = tail = newNode;        // New node becomes both head and tail
        } else {
            newNode->next = head;         // New node points forward to current head
            head->prev = newNode;         // Current head points back to new node
            head = newNode;               // Update head to point to new node
        }
    }

    // Insert new node at the end of the list
    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);  // Create new node with given value
        if (!head) {                      // If list is empty
            head = tail = newNode;        // New node becomes both head and tail
        } else {
            tail->next = newNode;         // Current tail points forward to new node
            newNode->prev = tail;         // New node points back to current tail
            tail = newNode;               // Update tail to point to new node
        }
    }

    // Insert new node at specified position (1-based indexing)
    void insertAtPosition(int pos, int val) {
        if (pos <= 1) {                   // If position is 1 or less
            insertAtStart(val);           // Insert at start
            return;
        }
        DNode* newNode = new DNode(val);  // Create new node
        DNode* temp = head;               // Temporary pointer for traversal
        
        // Traverse to node before target position
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }
        
        if (!temp || !temp->next) {       // If position exceeds list length
            insertAtEnd(val);             // Insert at end
        } else {
            newNode->next = temp->next;   // New node points forward to next node
            newNode->prev = temp;         // New node points back to previous node
            temp->next->prev = newNode;   // Next node points back to new node
            temp->next = newNode;         // Previous node points forward to new node
        }
    }

    // Delete the first node from the list
    void deleteAtStart() {
        if (!head) return;                // If list is empty, do nothing
        
        DNode* temp = head;               // Store reference to current head
        head = head->next;                // Move head to next node
        if (head) head->prev = nullptr;   // If list not empty, remove back pointer
        else tail = nullptr;              // If list becomes empty, update tail
        delete temp;                      // Free memory of deleted node
    }

    // Delete the last node from the list
    void deleteAtEnd() {
        if (!head) return;                // If list is empty, do nothing
        
        if (head == tail) {               // If only one node exists
            delete head;                  // Delete the single node
            head = tail = nullptr;        // Reset both pointers
            return;
        }
        
        DNode* temp = tail;               // Store reference to current tail
        tail = tail->prev;                // Move tail to previous node
        tail->next = nullptr;             // Remove forward pointer from new tail
        delete temp;                      // Free memory of deleted node
    }

    // Delete first node containing specific value
    void deleteAtValue(int val) {
        if (!head) return;                // If list is empty, do nothing

        // If head node contains the value
        if (head->data == val) {
            deleteAtStart();              // Use existing method
            return;
        }
        
        // If tail node contains the value
        if (tail->data == val) {
            deleteAtEnd();                // Use existing method
            return;
        }

        DNode* temp = head->next;         // Start search from second node
        // Find node with target value (skip head since already checked)
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        
        if (temp) {                       // If value found
            temp->prev->next = temp->next;  // Previous node bypasses current node
            if (temp->next) temp->next->prev = temp->prev;  // Next node points back to previous
            delete temp;                  // Free memory
        }
        // If value not found, silently do nothing
    }

        // ================= SORTING ALGORITHMS =================

    // Bubble Sort: repeatedly compares adjacent nodes and swaps if out of order
    void bubbleSort() {
        if (!head) return;   // Empty list, nothing to sort

        bool swapped;        // Flag to track if any swap happened
        DNode* current;
        DNode* last = nullptr;  // Marks the sorted portion at the end

        do {
            swapped = false;
            current = head;

            // Traverse until the last sorted node
            while (current->next != last) {
                if (current->data > current->next->data) {
                    // Swap data of current and next
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true; // Mark that a swap occurred
                }
                current = current->next;
            }
            last = current;  // Update the sorted boundary
        } while (swapped);   // Keep running until no swaps
    }

    // Selection Sort: finds minimum in unsorted part and swaps with current
    void selectionSort() {
        if (!head) return;   // Empty list, nothing to sort

        for (DNode* start = head; start && start->next; start = start->next) {
            DNode* minNode = start;
            // Find minimum node in the unsorted part
            for (DNode* current = start->next; current; current = current->next) {
                if (current->data < minNode->data) {
                    minNode = current;
                }
            }
            // Swap data between start and minNode
            if (minNode != start) {
                int temp = start->data;
                start->data = minNode->data;
                minNode->data = temp;
            }
        }
    }

    void insertionSort() {
        if (head == nullptr) return;
        DNode* sorted = nullptr;
        DNode* curr = head;
        // Traverse the list to sort each element
        while (curr != nullptr) {
            DNode* next = curr->next;                                   // Store the next node to process
            if (sorted == nullptr || sorted->data >= curr->data) {      // Insert `curr` into the sorted part
                curr->next = sorted;
                if (sorted != nullptr) sorted->prev = curr;             // If sorted is not empty, set its `prev`
                // Update sorted to the new head
                sorted = curr;
                sorted->prev = nullptr;
            }else {
                DNode* current_sorted = sorted;                     // Pointer to traverse the sorted part
                // Find the correct position to insert
                while (current_sorted->next != nullptr && current_sorted->next->data < curr->data) {
                    current_sorted = current_sorted->next;
                }
                curr->next = current_sorted->next;                  // Insert `curr` after `current_sorted`
                if (current_sorted->next != nullptr){               // Set `prev` if `curr` is not inserted at the end
                    current_sorted->next->prev = curr;
                }
                // Set `next` of `current_sorted` to `curr`
                current_sorted->next = curr;
                curr->prev = current_sorted;
            }
            curr = next;                                            // Move to the next node to be sorted
        }
        // Update Tail and Head
        head = sorted;
        tail = head;
        if (tail) {
            while (tail->next) {
                tail = tail->next;
            }
        }
    }


    // Display all elements in the list from head to tail
    void displayForward() {
        DNode* temp = head;               // Start from head
        while (temp) {                    // Traverse until null
            cout << temp->data << " <-> ";  // Print current node's data with double arrows
            temp = temp->next;            // Move to next node
        }
        cout << "NULL" << endl;           // Mark end of list
    }

    // Display all elements in the list from tail to head
    void displayBackward() {
        DNode* temp = tail;               // Start from tail
        while (temp) {                    // Traverse until null
            cout << temp->data << " <-> ";  // Print current node's data with double arrows
            temp = temp->prev;            // Move to previous node
        }
        cout << "NULL" << endl;           // Mark start of list
    }
};

// Main function to demonstrate doubly linked list operations
int main() {
    DoublyLinkedList dll;                 // Create empty doubly linked list
    
    // Insert operations
    dll.insertAtEnd(10);                  // List: 10
    dll.insertAtEnd(20);                  // List: 10 <-> 20
    dll.insertAtStart(15);                 // List: 5 <-> 10 <-> 20
    dll.insertAtStart(25);                 // List: 5 <-> 10 <-> 20
    dll.insertAtStart(5);                 // List: 5 <-> 10 <-> 20
    dll.insertAtStart(35);                 // List: 5 <-> 10 <-> 20
    dll.insertAtPosition(2, 15);          // List: 5 <-> 15 <-> 10 <-> 20

    cout << "Forward: ";
    dll.displayForward();                 // Display forward: 5 <-> 15 <-> 10 <-> 20 <-> NULL
    cout << "Backward: ";
    dll.displayBackward();                // Display backward: 20 <-> 10 <-> 15 <-> 5 <-> NULL

    // Delete operations
    dll.deleteAtStart();                  // Remove 5: 15 <-> 10 <-> 20
    dll.deleteAtEnd();                    // Remove 20: 15 <-> 10
    dll.deleteAtValue(15);                // Remove 15: 10

    cout << "After deletions forward: ";
    dll.displayForward();                 // Display final list: 10 <-> NULL

    dll.insertAtEnd(8);                  // List: 10
    dll.insertAtEnd(12);                  // List: 10 <-> 20
    dll.insertAtStart(15);                 // List: 5 <-> 10 <-> 20
    dll.insertAtStart(25);                 // List: 5 <-> 10 <-> 20
    dll.insertAtStart(7);                 // List: 5 <-> 10 <-> 20
    dll.insertAtStart(30);                 // List: 5 <-> 10 <-> 20
    dll.insertAtPosition(2, 15);          // List: 5 <-> 15 <-> 10 <-> 20

    cout << "\nBefore Sorting: ";
    dll.displayForward();

    // dll.bubbleSort();
    // cout << "After Bubble Sort: ";
    // dll.displayForward();

    // dll.selectionSort();
    // cout << "After Selection Sort: ";
    // dll.displayForward();

    dll.insertionSort();
    cout << "After Insertion Sort: ";
    dll.displayForward();
    return 0;
}