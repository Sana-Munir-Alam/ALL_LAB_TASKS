#include <iostream>
using namespace std;

// Node class represents individual elements in the linked list
class Node{
    public:
        int Value;              // Stores the actual data value of the node
        Node* next;             // Pointer to the next node in the list
        Node* prev;             // Pointer to the previous node in the list

        Node(int Val){          
            Value = Val;        // Set the node's value
            next = nullptr;     // Initialize next pointer to null (will be set later)
            prev = nullptr;     // Initialize prev pointer to null (will be set later)
        }
};

// CircularDoubleLinkedList class manages the entire linked list structure
class CircularDoubleLinkedList {
    public:
        Node* Head;             // Pointer to the first node in the list
        Node* Tail;             // Pointer to the last node in the list

        // Parametrized Constructor to initialize an empty list
        CircularDoubleLinkedList(){
            Head = NULL;        // Initialize head to null (empty list)
            Tail = NULL;        // Initialize tail to null (empty list)
        }
        
        // Insert a new node at the end of the list
        void InsertAtEnd(int Val){
            Node* newNode = new Node(Val);      // Create a new node with the given value
            if(Head == NULL){                   // Check if list is empty
                Head = newNode;                 // Set head to point to the new node
                Tail = newNode;                 // Set tail to point to the new node
                newNode->next = Head;           // Make the node point to itself (circular)
                newNode->prev = Head;  
                return;     
            }  else{                            // List is not empty - insert at end
                newNode->prev = Tail;           // New node's previous points to current tail
                newNode->next = Head;           // New node's next points to head (circular)
                Tail->next = newNode;           // Current tail's next points to new node
                Head->prev = newNode;           // Head's previous points to new node
                Tail = newNode;                 // Update tail to point to new last node
            }
        }
        // Insert a new node at the beginning of the list
        void InsertAtBeginning(int Val){
            Node* newNode = new Node(Val);      // Create a new node with the given value
            if (Head == NULL) {                 // Check if list is empty
                Head = newNode;                 // Set head to new node
                Tail = newNode;                 // Set tail to new node
                newNode->next = Head;           // Make node point to itself
                newNode->prev = Head;
            } else {                            // List is not empty - insert at beginning
                newNode->next = Head;           // New node's next points to current head
                newNode->prev = Tail;           // New node's prev points to tail (circular)
                Head->prev = newNode;           // Current head's prev points to new node
                Tail->next = newNode;           // Tail's next points to new node
                Head = newNode;                 // Update head to point to new first node
            }
        }
        
        void InsertAtPosition(int Val, int pos) {
            if (pos <= 0) {                     // If position is 0 or negative
                InsertAtBeginning(Val);         // Insert at beginning instead
                return;
            }
            Node* newNode = new Node(Val);      // Create new node
            Node* Current = Head;               // Start traversal from head
            for (int i = 0; i < pos && Current->next != Head; i++) {    // Traverse to the node at the desired position
                Current = Current->next;        // Move to next node
            }
            // Insert new node before the current node
            newNode->next = Current;            // New node's next points to current node
            newNode->prev = Current->prev;      // New node's prev points to current's previous
            Current->prev->next = newNode;      // Previous node's next points to new node
            Current->prev = newNode;            // Current node's prev points to new node

            if (Current == Head && pos == 0) {  // if inserting at position 0 before head
                Head = newNode;                 // Update head to new node
            }
        }

        void DeleteNode(int Val) {
            if (Head == NULL) return;           // If list is empty, do nothing
            Node* Current = Head;               // Start from head
            do {
                if (Current->Value == Val) {    // Found node to delete
                    if (Current == Head && Current == Tail) {
                        Head = NULL;            // Set head to null
                        Tail = NULL;            // Set tail to null
                    }else if (Current == Head) {             // Case 2: Deleting the head node (but not the only node)
                        Head = Head->next;                      // Move head to next node
                        Head->prev = Tail;                      // New head's prev points to tail
                        Tail->next = Head;                      // Tail's next points to new head
                    }else if (Current == Tail) {             // Case 3: Deleting the tail node
                        Tail = Tail->prev;                      // Move tail to previous node
                        Tail->next = Head;                      // New tail's next points to head
                        Head->prev = Tail;                      // Head's prev points to new tail
                    }else {                                  // Case 4: Deleting a middle node
                        Current->prev->next = Current->next;    // Bypass node forward
                        Current->next->prev = Current->prev;    // Bypass node backward
                    }
                    delete Current;             // Free the memory
                    return;                     // Exit after deletion
                }
                Current = Current->next;        // Move to next node
            } while (Current != Head);          // Continue until we circle back to head
        }

        void PrintList() {
            if (Head == NULL) {                 // Check if list is empty
                cout << "List is empty" << endl;
                return;
            }
            Node* Temp = Head;
            cout << "Circular Double Linked List (Forward): ";
            // Print list in forward direction
            do {
                cout << Temp->Value << " <-> "; // Print current node's value
                Temp = Temp->next;              // Move to next node
            } while (Temp != Head);             // Continue until we circle back to head
            cout << "(back to head)" << endl;

            // Print list in backward direction for verification
            Temp = Tail;
            cout << "Circular Double Linked List (Backward): ";
            do {
                cout << Temp->Value << " <-> "; // Print current node's value
                Temp = Temp->prev;              // Move to previous node
            } while (Temp != Tail);             // Continue until we circle back to tail
            cout << "(back to tail)" << endl;
        }
};

int main() {
    cout << "\n=== Circular Double Linked List ===" << endl;
    CircularDoubleLinkedList cdll;
    
    cdll.InsertAtEnd(100);         // List: 100
    cdll.InsertAtEnd(200);         // List: 100 <-> 200
    cdll.InsertAtEnd(300);         // List: 100 <-> 200 <-> 300
    cdll.InsertAtBeginning(50);    // List: 50 <-> 100 <-> 200 <-> 300
    cdll.InsertAtPosition(150, 2); // List: 50 <-> 100 <-> 150 <-> 200 <-> 300
    
    cdll.PrintList();              // Print the list in both directions
    
    cdll.DeleteNode(200);          // Delete node with value 200
    cout << "After deleting 200: \n";
    cdll.PrintList();              // Print updated list
    return 0;
}
