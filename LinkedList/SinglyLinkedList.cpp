#include <iostream>
using namespace std;


// Defining the Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the head node as NULL
struct Node* head = NULL;


// Insert at the beginning
void insert(int new_data) {
    struct Node* new_node = new Node();
    new_node -> data = new_data; // set data for the new node
    new_node -> next = head; // Set the new node's next pointer to the current head
    head = new_node; // point to the new node
}


// Insert a node at a specific position
void insertAtSpecificPosition(int new_data, int position) {
    struct Node* new_node = new Node(); //create the new node
    struct Node* temp = head; // create a traverser starting from the head
    new_node -> data = new_data; // set data for the new node
    new_node -> next = NULL; // set next to NULL

    if (position == 0) {
        new_node -> next = head;
        head = new_node; // if postion is 0, insert at befinnig
        return;
    }

    // Traverse to the node before the desired postion
    for (int i = 0; temp != NULL && i < position -1; i++) {
        temp = temp -> next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds " << endl;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}


// Insert at the end 
void insertAtEnd(int new_data) {
    struct Node* new_node = new Node();
    struct Node* temp = head;
    new_node -> data = new_data;
    new_node -> next = NULL; 

    if (head == NULL) {
        head = new_node;
        return;
    }

    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = new_node;
}


// Display the entire list
void display() {
    struct Node* ptr = head;
    if (ptr == NULL) {
        cout << "the list is empty" << endl;
        return;
    }

    cout << "The linked list is: ";
    while (ptr != NULL) {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}



int main() {
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(7);
    display();
    insertAtSpecificPosition(6, 4);
    display();
    insertAtEnd(9);
    display();
}




