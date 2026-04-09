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
        // Adding Node Backward
        void First(int Val){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            if(Head == NULL){               // Check if Head is NULL
                Head = newNode;             // It means this is the first Node we are upon/creating so The header pointer now points to this first node
                return;
            }else{  // If Node exist and We want to add this New Value before the Header
                newNode -> next = Head;     // Accessing Node CLass variable "next" using "->" This Links the new Node next pointer to the old Head ptr
                Head = newNode;             // Now we Write the New Value Address in to the Head ptr
            }
        }
        // A function that creates a linkedList whenever an object is created in MAIN
        // Adding Node Forward
        void Last(int Val){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            Node* Temp = Head;              // A temporaray Pointer That Has Head Address so that it can traverse across the LinkedList from START to find it's end
            while(Temp -> next != Tail){    // Traverse across the List as long as Temp Next pointer aint's pointing to NULL
                Temp = Temp -> next;        // Temp pointer points to the next location in the Index till it reaches NULL
            }
            Temp -> next = newNode;         // Now The Temp that was pointing to NULL initially will now point to the NEW NODE location 
            newNode -> next = Tail;         // Now the new node Next Pointer points to NULL
        }
        // A function that creates a linkedList whenever an object is created in MAIN
        // Adding Node in Between MY STYLE
        void Between(int Val, int StoredValue){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            Node* Temp = Head;              // A temporaray Pointer That Has Head Address so that it can traverse across the LinkedList from START to find the Part where we want to add the data
            while(Temp != NULL){            // Traverse across the List as long as Temp Next pointer aint's pointing to NULL
                if (Temp->Value == StoredValue){    // If the Current Pointer Value matches the location in which we ant to add Data in THEN...
                    Temp = Temp -> next;    // Storing the next node location at the Specific Value
                    break;                  // Get out of Loop
                }
            }
            newNode -> next = Temp->next;   // Storing the next location of other NODES after the addition of a NEW NODE in new node next pointer
            Temp -> next = newNode;         // Now The Temp that was pointing to Between OLD Data Next initially will now point to the NEW NODE location 
        }
        // SIR STYLE OF INSERTING VALUE IN BETWEEN
        void Middle(int Val, int pos){
            Node* newNode = new Node(Val);  // A node is being created in the Linked List with the required Value
            Node* Current = Head;
            Node* Pre;
            Current = Head;
            for (int i = 0; i < pos; i++){
                Pre = Current;              // Standing on the SPecific Position
                Current = Current -> next;  // Pointe to the next Value after that specific Position
            }
            Pre -> next = newNode;          // Now the Specific Location points to the New Node;
            newNode -> next = Current;      // Now the new node will point to the rest of the linked list node
        }

        void DeleteFromStart(){
            Node* Temp = Head;  // Start from the beginning of the List
            Head = Head->next;
            delete Temp;
        }

        void DeleteFromEnd(){
            Node* Temp = Head;              // Start from the beginning of the List
            Node* Pre;                      // A pointer that keeps record of previous Node
            while(Temp -> next != Tail){    // Traverse across the List as long as Temp Next pointer aint's pointing to NULL
                Pre = Temp;                 // Storing Old Location
                Temp = Temp -> next;        // Move to the next Location
            }
            Pre -> next = Tail;             // Changing Second Last Value to point to Tail aka NULL
            delete Temp;
        }
        
};
