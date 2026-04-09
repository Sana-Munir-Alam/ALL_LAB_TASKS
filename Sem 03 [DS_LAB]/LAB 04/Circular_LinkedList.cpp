#include <iostream>
using namespace std;

// Node class represents individual elements in the linked list
class Node{
    public:
        int Value;              // Stores the actual data value of the node
        Node* next;             // Pointer to the next node in the list

        // Constructor to initialize a new node
        Node(int Val){          
            Value = Val;        // Set the node's value
            next = nullptr;     // Initialize next pointer to null (will be set later)
        }
};

// CircularLinkedList class manages the entire linked list structure
class CircularLinkedList {
    public:
        Node* Head;             // Pointer to the first node in the list
        Node* Tail;             // Pointer to the last node in the list

        // Parametrized Constructor to initialize an empty list
        CircularLinkedList(){
            Head = NULL;        // Initialize head to null (empty list)
            Tail = NULL;        // Initialize tail to null (empty list)
        }
        
        // Insert a new node at the end of the list
        void InsertAtEnd(int Val){
            Node* newNode = new Node(Val);  // Create a new node with the given value
            if(Head == NULL){               // Check if list is empty
                Head = newNode;             // Set head to point to the new node
                Tail = newNode;             // Set tail to point to the new node
                newNode->next = Head;       // Make the node point to itself (circular)
                return;
            }else{                          // If list is not empty
                Tail->next = newNode;       // Current tail's next points to new node
                newNode->next = Head;       // New node's next points to head (maintain circularity)
                Tail = newNode;             // Update tail to point to the new last node
            }
        }

        // Insert a new node at the beginning of the list
        void InsertAtBeginning(int Val){
            Node* newNode = new Node(Val);  // Create a new node with the given value
            if (Head == NULL) {             // Check if list is empty
                Head = newNode;             // Set head to new node
                Tail = newNode;             // Set tail to new node
                newNode->next = Head;       // Make node point to itself
            } else {
                newNode->next = Head;       // New node points to current head
                Head = newNode;             // Update head to point to new node
                Tail->next = Head;          // Update tail to point to new head (maintain circularity)
            }
        }
        
        // Insert a new node at a specific position in the list
        void InsertAtPosition(int Val, int Pos){
            if (Pos <= 0) {                 // If position is 0 or negative
                InsertAtBeginning(Val);     // Insert at beginning instead
                return;
            }
            Node* newNode = new Node(Val);  // Create new node
            Node* Current = Head;           // Start traversal from head
            
            for (int i = 0; i < Pos - 1 && Current->next != Head; i++) {    // Traverse to the node before the desired position
                Current = Current->next;    // Move to next node
            }
            newNode->next = Current->next;  // New node points to current node's next
            Current->next = newNode;        // Current node points to new node

            // Check if we inserted after the tail
            if (newNode->next == Head) {
                Tail = newNode;             // Update tail if new node is now last
            }
        }
        // Delete a node with a specific value from the list
        void DeleteNode(int Val) {
            if (Head == NULL) return;           // If list is empty, do nothing
            Node* Current = Head;               // Start from head
            Node* Previous = Tail;              // Previous starts at tail (circular link)

            do {
                if (Current->Value == Val) {    // Found node to delete (Given value matches stored value)
                    if (Current == Head) {      // If deleting head node
                        Head = Head->next;      // Move head to next node
                        Tail->next = Head;      // Update tail to point to new head
                    } else if (Current == Tail) { // If deleting tail node
                        Tail = Previous;        // Update tail to previous node
                        Tail->next = Head;      // New tail points to head
                    } else {                    // If deleting middle node
                        Previous->next = Current->next; // Bypass the node to delete instead link previous next to current next
                    }
                    delete Current;             // Free the memory
                    return;                     // Exit after deletion won't continue ahead the list than. Only one occurence of that Value deletes
                }
                Previous = Current;             // Move previous pointer
                Current = Current->next;        // Move current pointer
            } while (Current != Head);          // Continue until we circle back to head (complete traversal of a circular lisr)
            //return;    // This return will make sure that all the occurences of that Same Value is deleted
        }

        void PrintList() {
            if (Head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            Node* Temp = Head;
            cout << "Circular Linked List: ";
            do {
                cout << Temp->Value << " -> ";
                Temp = Temp->next;
            } while (Temp != Head);
            
            cout << "(back to head)" << endl;
        }
        
};

int main() {
    cout << "=== Circular Single Linked List ===" << endl;
    CircularLinkedList cll;
    
    cll.InsertAtEnd(10);         // List: 10
    cll.InsertAtEnd(20);         // List: 10 -> 20
    cll.InsertAtEnd(30);         // List: 10 -> 20 -> 30
    cll.InsertAtBeginning(5);    // List: 5 -> 10 -> 20 -> 30
    cll.InsertAtEnd(20);         // List: 10 -> 20 -> 30 -> 20
    cll.InsertAtPosition(15, 2); // List: 5 -> 10 -> 15 -> 20 -> 30 -> 20
    
    cll.PrintList();
    
    cll.DeleteNode(20);          // Delete node with value 20 (Will delete the first occurence of 20 in the list).
                                 // To have all occurences of this value deleted you will have to uncomment the second return 
                                 // and comment the first return in the DeleteNdoe function
    cout << "After deleting 20: \n";
    cll.PrintList();             // Print updated list
    return 0;
}
