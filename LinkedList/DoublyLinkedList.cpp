#include <iostream>
using namespace std;


// Defining the Node Structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;


// insert a node at the beginning
void insert(int new_data) {
    struct Node* new_node = new Node(); // create a new node
    new_node -> data = new_data; // assign the data
    new_node -> next = head; // give the next pointer to the head
    new_node -> prev = NULL;
    if (head != NULL) {
        head -> prev = new_node; // set the prev pointer as NULL as it is head node

    } else {
        tail = new_node;
    }
    head = new_node;
}


// Insert at specific position
void insertAtSpecificPosition(int new_data, int position) {
    struct Node* new_node = new Node();
    struct Node* temp = head;
    new_node -> data = new_data;
    new_node -> next = NULL;
    new_node -> prev = NULL;

    if (position == 0) {
        new_node -> next = head;
        if (head != NULL) head -> prev = new_node;
        head = new_node;
        return;
    }
    
    // Traverse to the node before the desired position
    for (int i = 0; temp != NULL && i < position -1; i++) {
        temp = temp -> next;
    }

    if (temp == NULL ) {
        cout << "Position out of bounds" << endl;
    }
    
    new_node -> next = temp -> next; // set next pointer of new node to the next node of temp
    new_node -> prev = temp; // set the prev node to new node to temp
    if (temp -> next != NULL) temp -> next -> prev = new_node; // if there is next node to temp, we set new node as its previous pointer
    temp -> next = new_node;   // set next pointer of temp to new node
}


// Insert at end of list
void insertAtEnd(int new_data) {
    struct Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = NULL;
    if (tail == NULL) {
        new_node -> prev = NULL;
        head = tail = new_node;
        return;
    }

    new_node -> prev = tail;
    tail -> next = new_node;
    tail = new_node;
}


// Remove node at head
void removeFirst() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    struct Node* temp = head;
    head = head -> next;

    if (head != NULL) {
        head -> prev = NULL;
    } else { // list become empty
        tail = NULL;
    }
    
    delete temp;
}


// Remove node at tail
void removeLast(){
    if (tail == NULL) {
        cout << "list is empty" << endl;
        return;
    }

    struct Node* temp = tail;
    tail = tail -> prev;

    if (tail != NULL) {
        tail -> next = NULL;
    } else { // List becomes empty
        head = NULL;
    }
    
    delete temp;
}


// Display the entire list
void display(){
    struct Node* ptr = head;
    if (ptr == NULL) { // if the ptr is NUll means the list is empty
        cout << "the list is empty" << endl;
        return;
    }

    cout << "The DLL is : ";
    while (ptr != NULL) {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}


int main() {
    insertAtEnd(1);
    insert(2);
    insert(8);
    insert(7);
    insert(6);
    insert(5);
    insert(4);
    display();
    insertAtSpecificPosition(9, 4);
    display();
    insertAtEnd(3);
    display();
    insertAtEnd(4);
    display();
    removeFirst();
    display();
    removeLast();
    display();

}

