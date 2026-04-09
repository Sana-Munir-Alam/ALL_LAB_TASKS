#include <iostream>
using namespace std;

class Node{
    public:
        int Value;  // Data Storage Container
        Node* next; // A pointer that points to the next value

        Node(int Val){      // Parametrized Constructor
            Value = Val;
            next = nullptr;
        }
};

class SingleLinkedList {
    public:
        Node* Head; // Two important Pointers that help locate data whether when adding or retrieving or deleteing them
        Node* Tail;

        SingleLinkedList(){
            Head = NULL;
            Tail = NULL;
        }
        // A function that creates a Value in a linkedList whenever an object is created in MAIN
        // Adding Node Backward (like Node is inserted from Right to Left)
        void First(int Val){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            if(Head == NULL){               // Check if Head is NULL
                Head = Tail = newNode;      // It means this is the first Node we are upon/creating so The header pointer now points to this first node
                return;
            }else{  // If Node exist and We want to add this New Value before the Header
                newNode -> next = Head;     // Accessing Node CLass variable "next" using "->" This Links the new Node next pointer to the old Head ptr
                Head = newNode;             // Now we Write the New Value Address in to the Head ptr
            }
        }
        // A function that creates a linkedList whenever an object is created in MAIN
        // Adding Node Forward (Like Node is inserted from Left to Right)
        void Last(int Val){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            Node* Temp = Head;              // A temporaray Pointer That Has Head Address inorder to traverse across the LIST from START to find it's end
            if (Head == NULL) {             // Check if Head is NULL
                Head = Tail = newNode;
                return;
            }else {
                while(Temp -> next != NULL){    // Traverse across the List as long as Temp Next pointer aint's pointing to NULL
                    Temp = Temp -> next;        // Temp pointer points to the next location in the Index till it reaches NULL
                }
                Temp -> next = newNode;         // Now The Temp that was pointing to NULL initially will now point to the NEW NODE location 
                newNode -> next = NULL;         // Now the new node Next Pointer points to NULL
            }
        }
        // A function that creates a linkedList whenever an object is created in MAIN
        // Adding Node in Between MY STYLE
        void Between(int Val, int StoredValue){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            Node* Temp = Head;              // A temporaray Pointer That Has Head Address so that it can traverse across the LinkedList from START to Specific Part
            while(Temp != NULL){                    // Traverse across the List as long as Temp Next pointer aint's pointing to NULL
                if (Temp->Value == StoredValue){    // If the Current Pointer Value matches the location in which we ant to add Data in THEN...
                    newNode -> next = Temp -> next; // Storing the next node location at the new node next location
                    Temp -> next = newNode;         // Storing the Specific Value next pointer to the new node we just added
                    return;
                }
                Temp = Temp -> next;                // Moving to the next location
            }
        }

        void DeleteFromStart(){
            if (Head == NULL) return;   // List is already Empty so return
            Node* Temp = Head;          // Start from the beginning of the List
            Head = Head->next;
            delete Temp;
        }

        void DeleteFromEnd() {
            if (Head == NULL) return;   // Empty list

            if (Head->next == NULL) {   // Only one node in the list
                delete Head;
                Head = Tail = NULL;
                return;
            }
            Node* Temp = Head;
            while (Temp->next->next != NULL) {  // Stop at second-last node
                Temp = Temp->next;
            }
            delete Temp->next;      // Delete last node
            Temp->next = NULL;      // Now this is the last node
            Tail = Temp;            // Update tail
        }

        // Rearrange evens before odds
        void RearrangeEvenOdd() {
            if (Head == nullptr || Head->next == nullptr) return;   // Incase the linked list is empty

            Node* evenHead = NULL;                  // Start of Even List
            Node* evenTail = NULL;                  // End of Even List
            Node* oddHead = NULL;                   // Start of Odd List
            Node* oddTail = NULL;                   // End of Odd List

            Node* Current = Head;                   // Pointer that will be helping traverse original user given list

            while (Current != NULL) {               // Traverse across the List as long as Current ain't at to NULL
                if (Current->Value % 2 == 0) {      // Even
                    if (evenHead == NULL) {         // This will set the Even Head Pointer to the node which is the first Even Value
                        evenHead = evenTail = Current;
                    } else {
                        evenTail->next = Current;   // Otherwise, attach this node after the current evenTail.
                        evenTail = evenTail->next;  // Move evenTail forward to point at this new node.
                    }
                } else {                            // Odd
                    if (oddHead == nullptr) {       // This will set the Odd Head Pointer
                        oddHead = oddTail = Current;
                    } else {
                        oddTail->next = Current;    // Otherwise, attach this node after the current oddTail.
                        oddTail = oddTail->next;    // Move oddTail forward to point at this new node.
                    }
                }
                Current = Current->next;            // Advance the traversal pointer to the next node in the original list.
            }

            // If there are no evens or no odds, do nothing
            if (evenHead == nullptr || oddHead == nullptr) return;

            // Link even list with odd list
            evenTail->next = oddHead;
            oddTail->next = nullptr;

            // Update head and tail
            Head = evenHead;
            Tail = oddTail;
        }

        // Print Linked List
        void PrintList() {
            Node* Temp = Head;
            while (Temp != nullptr) {
                cout << Temp->Value;
                if (Temp->next != nullptr) cout << "->";
                Temp = Temp->next;
            }
            cout << "->NULL" << endl;
        }

        ~SingleLinkedList(){ 
            Node* Current = Head;               // Go to the start of header 
            while(Current != NULL){             // Traverse across the linked list until you reach the end/tail which is NULL 
                Node* nextNode = Current->next; // We store the next Node address in a pointer 
                delete Current;                 // We delete the Current node we standing on 
                Current = nextNode;             // We now store the next node address in the Current pointer and we have now moved to the next Node 
            } // This loop repeats until each and every node has been successfully deleted 
            cout << "LinkedList destroyed Successfully"; 
        } 

};

int main() {
    SingleLinkedList list;
    int choice, val, stored, n;

    do {
        cout << "\n====== Single Linked List Menu ======\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a value (Between)\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Rearrange Even-Odd\n";
        cout << "7. Print list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.First(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.Last(val);
                break;
            case 3:
                cout << "Enter new value: ";
                cin >> val;
                cout << "Enter value after which to insert: ";
                cin >> stored;
                list.Between(val, stored);
                break;
            case 4:
                list.DeleteFromStart();
                cout << "Deleted first element.\n";
                break;
            case 5:
                list.DeleteFromEnd();
                cout << "Deleted last element.\n";
                break;
            case 6:
                cout << "Enter number of elements: "; 
                cin >> n;
                cout << "Enter elements: "; 
                for (int i = 0; i < n; i++) { 
                    if (i == 0){ 
                        cin >> val; list.First(val); 
                    }else{ 
                        cin >> val; list.Last(val); 
                    } 
                } 
                cout << "\nORIGINAL LIST: "; 
                list.PrintList(); 
                list.RearrangeEvenOdd(); 
                cout << "\n\nMODIFIED LIST: "; 
                list.PrintList();
                cout << endl << endl;
                break;
            case 7:
                cout << "Current List: ";
                list.PrintList();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
