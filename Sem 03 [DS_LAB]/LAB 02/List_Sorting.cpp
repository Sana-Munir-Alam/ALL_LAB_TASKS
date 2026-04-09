#include <iostream>
using namespace std;

// Node class for Single Linked List elements
class Node {
public:
    int data;        // Stores the actual value
    Node* next;      // Pointer to the next node in the list
    
    // Constructor to initialize node with value and set next to null
    Node(int val) {
        data = val;
        next = nullptr;  // New node initially points to nothing
    }
};

// Single Linked List class implementation
class SinglyLinkedList {
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list

public:
    // Constructor - initializes empty list
    SinglyLinkedList() {
        head = tail = nullptr;  // Both pointers null when list is empty
    }

    // Insert new node at the beginning of the list
    void insertAtStart(int val) {
        Node* newNode = new Node(val);  // Create new node with given value
        if (!head) {                    // If list is empty
            head = tail = newNode;      // New node becomes both head and tail
        } else {
            newNode->next = head;       // New node points to current head
            head = newNode;             // Update head to point to new node
        }
    }

    // Insert new node at the end of the list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);  // Create new node with given value
        if (!head) {                    // If list is empty
            head = tail = newNode;      // New node becomes both head and tail
        } else {
            tail->next = newNode;       // Current tail points to new node
            tail = newNode;             // Update tail to point to new node
        }
    }

    // Insert new node at specified position (1-based indexing)
    void insertAtPosition(int pos, int val) {
        if (pos <= 1) {                 // If position is 1 or less
            insertAtStart(val);         // Insert at start
            return;
        }
        Node* newNode = new Node(val);  // Create new node
        Node* temp = head;              // Temporary pointer for traversal
        
        // Traverse to node before target position
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }
        
        if (!temp || !temp->next) {     // If position exceeds list length
            insertAtEnd(val);           // Insert at end
        } else {
            newNode->next = temp->next; // New node points to next node
            temp->next = newNode;       // Previous node points to new node
        }
    }

    // Delete the first node from the list
    void deleteAtStart() {
        if (!head) return;              // If list is empty, do nothing
        
        Node* temp = head;              // Store reference to current head
        head = head->next;              // Move head to next node
        if (!head) tail = nullptr;      // If list becomes empty, update tail
        delete temp;                    // Free memory of deleted node
    }

    // Delete the last node from the list
    void deleteAtEnd() {
        if (!head) return;              // If list is empty, do nothing
        
        if (head == tail) {             // If only one node exists
            delete head;                // Delete the single node
            head = tail = nullptr;      // Reset both pointers
            return;
        }
        
        Node* temp = head;
        // Traverse to node before tail
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;                    // Delete last node
        tail = temp;                    // Update tail to previous node
        tail->next = nullptr;           // Set new tail's next to null
    }

    // Delete first node containing specific value
    void deleteAtValue(int val) {
        if (!head) return;              // If list is empty, do nothing

        // If head node contains the value
        if (head->data == val) {
            deleteAtStart();            // Use existing method
            return;
        }

        Node* temp = head;
        // Find node before the target value
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        
        if (temp->next) {               // If value found
            Node* toDelete = temp->next;
            if (toDelete == tail) tail = temp;  // Update tail if deleting last node
            temp->next = toDelete->next;        // Bypass node to be deleted
            delete toDelete;             // Free memory
        }
        // If value not found, silently do nothing
    }

    // Display all elements in the list
    void display() {
        Node* temp = head;              // Start from head
        while (temp) {                  // Traverse until null
            cout << temp->data << " -> ";  // Print current node's data
            temp = temp->next;          // Move to next node
        }
        cout << "NULL" << endl;         // Mark end of list
    }
    // Inside SinglyLinkedList class

    // Bubble Sort
    void bubbleSort() {
        // Base case: if list is empty or has only one element, it's already sorted
        if (!head || !head->next) return;

        bool swapped;        // Flag to track if any swaps occurred in a pass
        Node* end = nullptr; // Pointer to mark the end of unsorted portion
        
        // Outer loop: continues until no swaps occur in a complete pass
        do {
            swapped = false;        // Reset swap flag for each new pass
            Node* current = head;   // Start from the beginning of the list
            // Inner loop: traverse through the unsorted portion of the list
            while (current->next != end) {
                if (current->data > current->next->data) {  // Compare adjacent nodes
                    // Swap the data values (not the nodes themselves)
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true; // Mark that a swap occurred
                }
                current = current->next; // Move to next node
            }
            // After each pass, the largest element in unsorted portion  bubbles up to the end, so we mark it as sorted
            end = current;
        } while (swapped); // Continue until no swaps occur in a complete pass
    }

    // Selection Sort
    void selectionSort() {
        // Outer loop: traverse through each node in the list
        for (Node* i = head; i != nullptr; i = i->next) {
            Node* minNode = i;  // Assume current node (i) is the minimum
            
            // Inner loop: find the actual minimum node in the remaining unsorted portion
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (j->data < minNode->data) {
                    minNode = j; // Update minNode if smaller value found
                }
            }
            // Swap the data values between current node (i) and the minimum node found
            int temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
            
            /*
            HOW IT WORKS (List: 5 → 3 → 8 → 1):
            
            Pass 1 (i points to 5):
            Find min in remaining list: 3 → 8 → 1 → min is 1
            Swap 5 and 1 → List: 1 → 3 → 8 → 5
            
            Pass 2 (i points to 3):
            Find min in remaining list: 8 → 5 → min is 3 (itself)
            No swap needed → List: 1 → 3 → 8 → 5
            
            Pass 3 (i points to 8):
            Find min in remaining list: 5 → min is 5
            Swap 8 and 5 → List: 1 → 3 → 5 → 8
            
            Pass 4 (i points to 8): Only one element, already sorted
            */
        }
    }

    // Insertion Sort
    void insertionSort() {
        // Base case: empty list or single element list is already sorted
        if (!head || !head->next) return;
        
        Node* sorted = nullptr; // Initialize empty sorted list (will build this gradually)
        
        // Process each node from the original list until it's empty
        while (head) {
            // Detach the first node from original list
            Node* current = head;      // Store current node to be inserted
            head = head->next;         // Move head to next node in original list
            current->next = nullptr;   // Detach current node completely from original list
            
            // Case 1: Insert at beginning of sorted list (or when sorted list is empty)
            // - If sorted list is empty (!sorted)
            // - OR current node data is <= first node of sorted list
            if (!sorted || sorted->data >= current->data) {
                current->next = sorted; // Point current node to existing sorted list
                sorted = current;       // Make current node the new head of sorted list
            } 
            // Case 2: Insert somewhere in the middle or end of sorted list
            else {
                Node* temp = sorted; // Start from beginning of sorted list
                
                // Traverse sorted list to find the correct insertion position
                // Stop when: 
                // - temp->next is null (end of list), OR
                // - temp->next->data >= current->data (found insertion point)
                while (temp->next && temp->next->data < current->data) {
                    temp = temp->next; // Move to next node in sorted list
                }
                
                // Insert current node after temp node
                current->next = temp->next; // Connect current to rest of list
                temp->next = current;       // Connect previous node to current
            }
            
            /*
            HOW INSERTION SORT WORKS (List: 5 → 3 → 8 → 1):
            
            Step 1: current = 5, sorted = null
            Insert 5 at beginning → sorted: 5
            
            Step 2: current = 3, sorted: 5
            3 < 5 → insert at beginning → sorted: 3 → 5
            
            Step 3: current = 8, sorted: 3 → 5
            8 > 5 → find position: after 5 → sorted: 3 → 5 → 8
            
            Step 4: current = 1, sorted: 3 → 5 → 8
            1 < 3 → insert at beginning → sorted: 1 → 3 → 5 → 8
            */
        }
        
        // Update head to point to the newly sorted list
        head = sorted;
        
        // Update tail pointer to the end of the sorted list (Important for maintaining proper list structure)
        tail = head;
        while (tail && tail->next) {
            tail = tail->next; // Traverse to last node
        }
    }
};

int main() {
    SinglyLinkedList sll;

    sll.insertAtEnd(40);
    sll.insertAtEnd(10);
    sll.insertAtEnd(30);
    sll.insertAtEnd(5);
    sll.insertAtEnd(20);

    cout << "Original List: ";
    sll.display();

    // cout << "After Bubble Sort: ";
    // sll.bubbleSort();
    // sll.display();

    // sll.insertAtEnd(15);
    // sll.insertAtEnd(25);
    // cout << "Before Selection Sort: ";
    // sll.display();

    // cout << "After Selection Sort: ";
    // sll.selectionSort();
    // sll.display();

    sll.insertAtEnd(35);
    sll.insertAtEnd(1);
    cout << "Before Insertion Sort: ";
    sll.display();

    cout << "After Insertion Sort: ";
    sll.insertionSort();
    sll.display();

    return 0;
}
