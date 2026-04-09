// #include <iostream>
// using namespace std;

// int main() {
//     int x = 10;
//     int *ptr = &x;   // pointer stores address of x

//     cout << "Value of x = " << x << endl;
//     cout << "Address of x = " << &x << endl;
//     cout << "Value stored in ptr = " << ptr << endl;
//     cout << "Value pointed by ptr = " << *ptr << endl;

//     return 0;
// }

//=======================
//
// BASIC RULE of THREE
//
//=======================

// #include <iostream>
// using namespace std;

// class MyArray {
//     int *data;
//     int size;

// public:
//     // Constructor
//     MyArray(int s) {
//         size = s;
//         data = new int[size];
//         for (int i = 0; i < size; i++) data[i] = 0;
//     }

//     // Destructor
//     ~MyArray() {
//         delete[] data;   // release memory
//     }

//     // Copy Constructor
//     MyArray(const MyArray &other) {
//         size = other.size;
//         data = new int[size];
//         for (int i = 0; i < size; i++) data[i] = other.data[i];
//     }

//     // Copy Assignment Operator
//     MyArray& operator=(const MyArray &other) {
//         if (this != &other) { // avoid self-assignment
//             delete[] data;    // release old memory
//             size = other.size;
//             data = new int[size];
//             for (int i = 0; i < size; i++) data[i] = other.data[i];
//         }
//         return *this;
//     }

//     void display() {
//         for (int i = 0; i < size; i++) cout << data[i] << " ";
//         cout << endl;
//     }
// };

// int main() {
//     MyArray a1(5);
//     MyArray a2 = a1;  // Copy constructor
//     MyArray a3(3);
//     a3 = a1;          // Copy assignment
//     cout << "A1: ";
//     a1.display();
//     cout << endl;
//     cout << "A2: ";
//     a2.display();
//     cout << endl;
//     cout << "A3: ";
//     a3.display();
//     cout << endl;
// }


//=======================
//
// ADVANCED RULE of THREE 2D, DMA, Rule of THREE
//
//=======================

// #include <iostream>
// using namespace std;

// class Matrix {
//     int **data;
//     int rows, cols;

// public:
//     // Constructor
//     Matrix(int r, int c) {
//         rows = r;
//         cols = c;
//         data = new int*[rows];
//         for (int i = 0; i < rows; i++)
//             data[i] = new int[cols];

//         // Initialize with 0
//         for (int i = 0; i < rows; i++)
//             for (int j = 0; j < cols; j++)
//                 data[i][j] = 0;
//     }

//     // Destructor
//     ~Matrix() {
//         for (int i = 0; i < rows; i++)
//             delete[] data[i];
//         delete[] data;
//     }

//    // Copy Constructor (Deep Copy)
    // Matrix(const Matrix &other) {
    //     rows = other.rows;
    //     cols = other.cols;
    //     data = new int*[rows];
    //     for (int i = 0; i < rows; i++)
    //         data[i] = new int[cols];

    //     for (int i = 0; i < rows; i++)
    //         for (int j = 0; j < cols; j++)
    //             data[i][j] = other.data[i][j];
    // }

    // // Copy Assignment Operator
    // Matrix& operator=(const Matrix &other) {
    //     if (this != &other) {  // Avoid self-assignment
    //         // Free old memory
    //         for (int i = 0; i < rows; i++) delete[] data[i];
    //         delete[] data;

    //         // Allocate new
    //         rows = other.rows;
    //         cols = other.cols;
    //         data = new int*[rows];
    //         for (int i = 0; i < rows; i++) 
    //             data[i] = new int[cols];

    //         // Copy elements
    //         for (int i = 0; i < rows; i++)
    //             for (int j = 0; j < cols; j++) 
    //                 data[i][j] = other.data[i][j];
    //     }
    //     return *this;
    // }

//     // Function to input values
//     void input() {
//         cout << "Enter elements (" << rows << "x" << cols << "):\n";
//         for (int i = 0; i < rows; i++)
//             for (int j = 0; j < cols; j++)
//                 cin >> data[i][j];
//     }

//     // Function to display
//     void display() {
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++)
//                 cout << data[i][j] << " ";
//             cout << endl;
//         }
//     }
// };

// int main() {
//     Matrix m1(2, 3);   // 2x3 matrix
//     m1.input();

//     cout << "Matrix m1:\n";
//     m1.display();

//     Matrix m2 = m1;   // Copy Constructor
//     cout << "Matrix m2 (copied from m1):\n";
//     m2.display();

//     Matrix m3(2, 2);
//     m3 = m1;          // Copy Assignment
//     cout << "Matrix m3 (assigned from m1):\n";
//     m3.display();

//     return 0;
// }









//=======================
//
// SINGLY LINKED LIST
//
//=======================

// #include <iostream>
// using namespace std;

// // Node class for Single Linked List elements
// class Node {
// public:
//     int data;        // Stores the actual value
//     Node* next;      // Pointer to the next node in the list
    
//     // Constructor to initialize node with value and set next to null
//     Node(int val) {
//         data = val;
//         next = nullptr;  // New node initially points to nothing
//     }
// };

// // Single Linked List class implementation
// class SinglyLinkedList {
//     Node* head;  // Pointer to the first node in the list
//     Node* tail;  // Pointer to the last node in the list

// public:
//     // Constructor - initializes empty list
//     SinglyLinkedList() {
//         head = tail = nullptr;  // Both pointers null when list is empty
//     }

//     // Insert new node at the beginning of the list
//     void insertAtStart(int val) {
//         Node* newNode = new Node(val);  // Create new node with given value
//         if (!head) {                    // If list is empty
//             head = tail = newNode;      // New node becomes both head and tail
//         } else {
//             newNode->next = head;       // New node points to current head
//             head = newNode;             // Update head to point to new node
//         }
//     }

//     // Insert new node at the end of the list
//     void insertAtEnd(int val) {
//         Node* newNode = new Node(val);  // Create new node with given value
//         if (!head) {                    // If list is empty
//             head = tail = newNode;      // New node becomes both head and tail
//         } else {
//             tail->next = newNode;       // Current tail points to new node
//             tail = newNode;             // Update tail to point to new node
//         }
//     }

//     // Insert new node at specified position (1-based indexing)
//     void insertAtPosition(int pos, int val) {
//         if (pos <= 1) {                 // If position is 1 or less
//             insertAtStart(val);         // Insert at start
//             return;
//         }
//         Node* newNode = new Node(val);  // Create new node
//         Node* temp = head;              // Temporary pointer for traversal
        
//         // Traverse to node before target position
//         for (int i = 1; temp && i < pos - 1; i++) {
//             temp = temp->next;
//         }
        
//         if (!temp || !temp->next) {     // If position exceeds list length
//             insertAtEnd(val);           // Insert at end
//         } else {
//             newNode->next = temp->next; // New node points to next node
//             temp->next = newNode;       // Previous node points to new node
//         }
//     }

//     // Delete the first node from the list
//     void deleteAtStart() {
//         if (!head) return;              // If list is empty, do nothing
        
//         Node* temp = head;              // Store reference to current head
//         head = head->next;              // Move head to next node
//         if (!head) tail = nullptr;      // If list becomes empty, update tail
//         delete temp;                    // Free memory of deleted node
//     }

//     // Delete the last node from the list
//     void deleteAtEnd() {
//         if (!head) return;              // If list is empty, do nothing
        
//         if (head == tail) {             // If only one node exists
//             delete head;                // Delete the single node
//             head = tail = nullptr;      // Reset both pointers
//             return;
//         }
        
//         Node* temp = head;
//         // Traverse to node before tail
//         while (temp->next != tail) {
//             temp = temp->next;
//         }
//         delete tail;                    // Delete last node
//         tail = temp;                    // Update tail to previous node
//         tail->next = nullptr;           // Set new tail's next to null
//     }

//     // Delete first node containing specific value
//     void deleteAtValue(int val) {
//         if (!head) return;              // If list is empty, do nothing

//         // If head node contains the value
//         if (head->data == val) {
//             deleteAtStart();            // Use existing method
//             return;
//         }

//         Node* temp = head;
//         // Find node before the target value
//         while (temp->next && temp->next->data != val) {
//             temp = temp->next;
//         }
        
//         if (temp->next) {               // If value found
//             Node* toDelete = temp->next;
//             if (toDelete == tail) tail = temp;  // Update tail if deleting last node
//             temp->next = toDelete->next;        // Bypass node to be deleted
//             delete toDelete;             // Free memory
//         }
//         // If value not found, silently do nothing
//     }

//     // Display all elements in the list
//     void display() {
//         Node* temp = head;              // Start from head
//         while (temp) {                  // Traverse until null
//             cout << temp->data << " -> ";  // Print current node's data
//             temp = temp->next;          // Move to next node
//         }
//         cout << "NULL" << endl;         // Mark end of list
//     }
// };

// // Main function to demonstrate linked list operations
// int main() {
//     SinglyLinkedList sll;               // Create empty linked list
    
//     // Insert operations
//     sll.insertAtEnd(10);                // List: 10
//     sll.insertAtEnd(20);                // List: 10 -> 20
//     sll.insertAtStart(5);               // List: 5 -> 10 -> 20
//     sll.insertAtPosition(2, 15);        // List: 5 -> 15 -> 10 -> 20
//     sll.insertAtPosition(3, 19);        // List: 5 -> 15 -> 19 -> 10 -> 20

//     cout << "List after insertions: ";
//     sll.display();                      // Display current list

//     cout << "List after deletions Start: ";
//     // Delete operations
//     sll.deleteAtStart();                // Remove 5: 15 -> 10 -> 20
//     sll.display();
//     cout << "List after deletions End: ";
//     sll.deleteAtEnd();                  // Remove 20: 15 -> 10
//     sll.display();
//     cout << "List after deletions Specific: ";
//     sll.deleteAtValue(19);              // Remove 15: 10
//     sll.display();                      // Display final list

//     return 0;
// }









//=======================
//
// DOUBLE LINKED LIST
//
//=======================

// #include <iostream>
// using namespace std;

// // Node class for Doubly Linked List elements
// class DNode {
// public:
//     int data;        // Stores the actual value
//     DNode* next;     // Pointer to the next node in the list
//     DNode* prev;     // Pointer to the previous node in the list
    
//     // Constructor to initialize node with value and set pointers to null
//     DNode(int val) {
//         data = val;
//         next = prev = nullptr;  // New node initially points to nothing in both directions
//     }
// };

// // Doubly Linked List class implementation
// class DoublyLinkedList {
//     DNode* head;  // Pointer to the first node in the list
//     DNode* tail;  // Pointer to the last node in the list

// public:
//     // Constructor - initializes empty list
//     DoublyLinkedList() {
//         head = tail = nullptr;  // Both pointers null when list is empty
//     }

//     // Insert new node at the beginning of the list
//     void insertAtStart(int val) {
//         DNode* newNode = new DNode(val);  // Create new node with given value
//         if (!head) {                      // If list is empty
//             head = tail = newNode;        // New node becomes both head and tail
//         } else {
//             newNode->next = head;         // New node points forward to current head
//             head->prev = newNode;         // Current head points back to new node
//             head = newNode;               // Update head to point to new node
//         }
//     }

//     // Insert new node at the end of the list
//     void insertAtEnd(int val) {
//         DNode* newNode = new DNode(val);  // Create new node with given value
//         if (!head) {                      // If list is empty
//             head = tail = newNode;        // New node becomes both head and tail
//         } else {
//             tail->next = newNode;         // Current tail points forward to new node
//             newNode->prev = tail;         // New node points back to current tail
//             tail = newNode;               // Update tail to point to new node
//         }
//     }

//     // Insert new node at specified position (1-based indexing)
//     void insertAtPosition(int pos, int val) {
//         if (pos <= 1) {                   // If position is 1 or less
//             insertAtStart(val);           // Insert at start
//             return;
//         }
//         DNode* newNode = new DNode(val);  // Create new node
//         DNode* temp = head;               // Temporary pointer for traversal
        
//         // Traverse to node before target position
//         for (int i = 1; temp && i < pos - 1; i++) {
//             temp = temp->next;
//         }
        
//         if (!temp || !temp->next) {       // If position exceeds list length
//             insertAtEnd(val);             // Insert at end
//         } else {
//             newNode->next = temp->next;   // New node points forward to next node
//             newNode->prev = temp;         // New node points back to previous node
//             temp->next->prev = newNode;   // Next node points back to new node
//             temp->next = newNode;         // Previous node points forward to new node
//         }
//     }

//     // Delete the first node from the list
//     void deleteAtStart() {
//         if (!head) return;                // If list is empty, do nothing
        
//         DNode* temp = head;               // Store reference to current head
//         head = head->next;                // Move head to next node
//         if (head) head->prev = nullptr;   // If list not empty, remove back pointer
//         else tail = nullptr;              // If list becomes empty, update tail
//         delete temp;                      // Free memory of deleted node
//     }

//     // Delete the last node from the list
//     void deleteAtEnd() {
//         if (!head) return;                // If list is empty, do nothing
        
//         if (head == tail) {               // If only one node exists
//             delete head;                  // Delete the single node
//             head = tail = nullptr;        // Reset both pointers
//             return;
//         }
        
//         DNode* temp = tail;               // Store reference to current tail
//         tail = tail->prev;                // Move tail to previous node
//         tail->next = nullptr;             // Remove forward pointer from new tail
//         delete temp;                      // Free memory of deleted node
//     }

//     // Delete first node containing specific value
//     void deleteAtValue(int val) {
//         if (!head) return;                // If list is empty, do nothing

//         // If head node contains the value
//         if (head->data == val) {
//             deleteAtStart();              // Use existing method
//             return;
//         }
        
//         // If tail node contains the value
//         if (tail->data == val) {
//             deleteAtEnd();                // Use existing method
//             return;
//         }

//         DNode* temp = head->next;         // Start search from second node
//         // Find node with target value (skip head since already checked)
//         while (temp && temp->data != val) {
//             temp = temp->next;
//         }
        
//         if (temp) {                       // If value found
//             temp->prev->next = temp->next;  // Previous node bypasses current node
//             if (temp->next) temp->next->prev = temp->prev;  // Next node points back to previous
//             delete temp;                  // Free memory
//         }
//         // If value not found, silently do nothing
//     }

//     // Display all elements in the list from head to tail
//     void displayForward() {
//         DNode* temp = head;               // Start from head
//         while (temp) {                    // Traverse until null
//             cout << temp->data << " <-> ";  // Print current node's data with double arrows
//             temp = temp->next;            // Move to next node
//         }
//         cout << "NULL" << endl;           // Mark end of list
//     }

//     // Display all elements in the list from tail to head
//     void displayBackward() {
//         DNode* temp = tail;               // Start from tail
//         while (temp) {                    // Traverse until null
//             cout << temp->data << " <-> ";  // Print current node's data with double arrows
//             temp = temp->prev;            // Move to previous node
//         }
//         cout << "NULL" << endl;           // Mark start of list
//     }
// };

// // Main function to demonstrate doubly linked list operations
// int main() {
//     DoublyLinkedList dll;                 // Create empty doubly linked list
    
//     // Insert operations
//     dll.insertAtEnd(10);                  // List: 10
//     dll.insertAtEnd(20);                  // List: 10 <-> 20
//     dll.insertAtStart(5);                 // List: 5 <-> 10 <-> 20
//     dll.insertAtPosition(2, 15);          // List: 5 <-> 15 <-> 10 <-> 20

//     cout << "Forward: ";
//     dll.displayForward();                 // Display forward: 5 <-> 15 <-> 10 <-> 20 <-> NULL
//     cout << "Backward: ";
//     dll.displayBackward();                // Display backward: 20 <-> 10 <-> 15 <-> 5 <-> NULL

//     // Delete operations
//     dll.deleteAtStart();                  // Remove 5: 15 <-> 10 <-> 20
//     dll.deleteAtEnd();                    // Remove 20: 15 <-> 10
//     dll.deleteAtValue(15);                // Remove 15: 10

//     cout << "After deletions forward: ";
//     dll.displayForward();                 // Display final list: 10 <-> NULL

//     return 0;
// }









//=======================
//
// CIRCULAR SINGLE LINKED LIST
//
//=======================

// #include <iostream>
// using namespace std;

// // Node class represents individual elements in the linked list
// class Node{
//     public:
//         int Value;              // Stores the actual data value of the node
//         Node* next;             // Pointer to the next node in the list

//         // Constructor to initialize a new node
//         Node(int Val){          
//             Value = Val;        // Set the node's value
//             next = nullptr;     // Initialize next pointer to null (will be set later)
//         }
// };

// // CircularLinkedList class manages the entire linked list structure
// class CircularLinkedList {
//     public:
//         Node* Head;             // Pointer to the first node in the list
//         Node* Tail;             // Pointer to the last node in the list

//         // Parametrized Constructor to initialize an empty list
//         CircularLinkedList(){
//             Head = NULL;        // Initialize head to null (empty list)
//             Tail = NULL;        // Initialize tail to null (empty list)
//         }
        
//         // Insert a new node at the end of the list
//         void InsertAtEnd(int Val){
//             Node* newNode = new Node(Val);  // Create a new node with the given value
//             if(Head == NULL){               // Check if list is empty
//                 Head = newNode;             // Set head to point to the new node
//                 Tail = newNode;             // Set tail to point to the new node
//                 newNode->next = Head;       // Make the node point to itself (circular)
//                 return;
//             }else{                          // If list is not empty
//                 Tail->next = newNode;       // Current tail's next points to new node
//                 newNode->next = Head;       // New node's next points to head (maintain circularity)
//                 Tail = newNode;             // Update tail to point to the new last node
//             }
//         }

//         // Insert a new node at the beginning of the list
//         void InsertAtBeginning(int Val){
//             Node* newNode = new Node(Val);  // Create a new node with the given value
//             if (Head == NULL) {             // Check if list is empty
//                 Head = newNode;             // Set head to new node
//                 Tail = newNode;             // Set tail to new node
//                 newNode->next = Head;       // Make node point to itself
//             } else {
//                 newNode->next = Head;       // New node points to current head
//                 Head = newNode;             // Update head to point to new node
//                 Tail->next = Head;          // Update tail to point to new head (maintain circularity)
//             }
//         }
        
//         // Insert a new node at a specific position in the list
//         void InsertAtPosition(int Val, int Pos){
//             if (Pos <= 0) {                 // If position is 0 or negative
//                 InsertAtBeginning(Val);     // Insert at beginning instead
//                 return;
//             }
//             Node* newNode = new Node(Val);  // Create new node
//             Node* Current = Head;           // Start traversal from head
            
//             for (int i = 0; i < Pos - 1 && Current->next != Head; i++) {    // Traverse to the node before the desired position
//                 Current = Current->next;    // Move to next node
//             }
//             newNode->next = Current->next;  // New node points to current node's next
//             Current->next = newNode;        // Current node points to new node

//             // Check if we inserted after the tail
//             if (newNode->next == Head) {
//                 Tail = newNode;             // Update tail if new node is now last
//             }
//         }
//         // Delete a node with a specific value from the list
//         void DeleteNode(int Val) {
//             if (Head == NULL) return;           // If list is empty, do nothing
//             Node* Current = Head;               // Start from head
//             Node* Previous = Tail;              // Previous starts at tail (circular link)

//             do {
//                 if (Current->Value == Val) {    // Found node to delete (Given value matches stored value)
//                     if (Current == Head) {      // If deleting head node
//                         Head = Head->next;      // Move head to next node
//                         Tail->next = Head;      // Update tail to point to new head
//                     } else if (Current == Tail) { // If deleting tail node
//                         Tail = Previous;        // Update tail to previous node
//                         Tail->next = Head;      // New tail points to head
//                     } else {                    // If deleting middle node
//                         Previous->next = Current->next; // Bypass the node to delete instead link previous next to current next
//                     }
//                     delete Current;             // Free the memory
//                     return;                     // Exit after deletion won't continue ahead the list than. Only one occurence of that Value deletes
//                 }
//                 Previous = Current;             // Move previous pointer
//                 Current = Current->next;        // Move current pointer
//             } while (Current != Head);          // Continue until we circle back to head (complete traversal of a circular lisr)
//             //return;    // This return will make sure that all the occurences of that Same Value is deleted
//         }

//          // Delete first node
//         void DeleteAtStart() {
//             if (Head == NULL) return;   
//             if (Head == Tail) {         
//                 delete Head;
//                 Head = Tail = NULL;
//                 return;
//             }
//             Node* temp = Head;          
//             Head = Head->next;          
//             Tail->next = Head;          
//             delete temp;                
//         }

//         // Delete last node
//         void DeleteAtEnd() {
//             if (Head == NULL) return;   
//             if (Head == Tail) {         
//                 delete Head;
//                 Head = Tail = NULL;
//                 return;
//             }
//             Node* temp = Head;
//             // Traverse to node before tail
//             while (temp->next != Tail) {
//                 temp = temp->next;
//             }
//             delete Tail;                    // Delete last node
//             Tail = temp;                    // Update tail
//             Tail->next = Head;              // Maintain circularity      
//         }

//         void PrintList() {
//             if (Head == NULL) {
//                 cout << "List is empty" << endl;
//                 return;
//             }
//             Node* Temp = Head;
//             cout << "Circular Linked List: ";
//             do {
//                 cout << Temp->Value << " -> ";
//                 Temp = Temp->next;
//             } while (Temp != Head);
            
//             cout << "(back to head)" << endl;
//         }
        
// };

// int main() {
//     cout << "=== Circular Single Linked List ===" << endl;
//     CircularLinkedList cll;
    
//     cll.InsertAtEnd(10);         // List: 10
//     cll.InsertAtEnd(20);         // List: 10 -> 20
//     cll.InsertAtEnd(30);         // List: 10 -> 20 -> 30
//     cll.InsertAtBeginning(5);    // List: 5 -> 10 -> 20 -> 30
//     cll.InsertAtEnd(20);         // List: 10 -> 20 -> 30 -> 20
//     cll.InsertAtPosition(15, 2); // List: 5 -> 10 -> 15 -> 20 -> 30 -> 20
    
//     cll.PrintList();
    
//     cll.DeleteNode(20);          // Delete node with value 20 (Will delete the first occurence of 20 in the list).
//                                  // To have all occurences of this value deleted you will have to uncomment the second return 
//                                  // and comment the first return in the DeleteNdoe function
//     cout << "After deleting 20: \n";
//     cll.PrintList();             // Print updated list

//     cout << "\nDeleting at start:" << endl;
//     cll.DeleteAtStart();
//     cll.PrintList();

//     cout << "\nDeleting at end:" << endl;
//     cll.DeleteAtEnd();
//     cll.PrintList();

//     cout << "\nDeleting node with value 30:" << endl;
//     cll.DeleteNode(30);
//     cll.PrintList();
//     return 0;
// }









//=======================
//
// CIRCULAR DOUBLE LINKED LIST
//
//=======================

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
        // Delete first node
        void DeleteAtStart() {
            if (Head == NULL) return;   // Empty list

            if (Head == Tail) {         // Only one node
                delete Head;
                Head = Tail = NULL;
                return;
            }

            Node* temp = Head;          // Store old head
            Head = Head->next;          // Move head forward
            Head->prev = Tail;          // Fix new head's prev
            Tail->next = Head;          // Fix circularity
            delete temp;                // Free old head
        }

        // Delete last node
        void DeleteAtEnd() {
            if (Head == NULL) return;   // Empty list

            if (Head == Tail) {         // Only one node
                delete Head;
                Head = Tail = NULL;
                return;
            }

            Node* temp = Tail;          // Store old tail
            Tail = Tail->prev;          // Move tail backward
            Tail->next = Head;          // Fix circularity
            Head->prev = Tail;          // Fix head's prev
            delete temp;                // Free old tail
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
    cout << "\nDeleting at start:" << endl;
    cdll.DeleteAtStart();
    cdll.PrintList();

    cout << "\nDeleting at end:" << endl;
    cdll.DeleteAtEnd();
    cdll.PrintList();

    cout << "\nDeleting node with value 300:" << endl;
    cdll.DeleteNode(100);
    cdll.PrintList();

    return 0;
}