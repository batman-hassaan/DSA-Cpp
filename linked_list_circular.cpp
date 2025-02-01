#include <iostream>
using namespace std;

class Node {
public:
    int data;     // Data in the node
    Node* next;   // Pointer to the next node

    // Constructor to initialize the node
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to insert a node at the end of a circular linked list
void insertEnd(Node* &tail, int value) {
    Node* newNode = new Node(value);
    
    if (tail == NULL) {
        // If the list is empty, initialize the first node
        tail = newNode;
        tail->next = tail;  // Point to itself, forming a single-node circle
    } else {
        newNode->next = tail->next;  // New node's next points to head (tail->next is head)
        tail->next = newNode;        // Tail's next points to the new node
        tail = newNode;              // Update tail to the new node
    }
}

// Function to print the circular linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Node* temp = tail->next;  // Start from head (tail->next is head)
    do {
        cout << "The element is: " << temp->data << endl;
        temp = temp->next;
    } while (temp != tail->next);  // Loop until we come back to the head
}

int main() {
    Node* tail = NULL;  // Initialize an empty list with tail pointing to NULL
    
    // Insert nodes into the circular linked list
    insertEnd(tail, 10);
    insertEnd(tail, 20);
    insertEnd(tail, 30);
    
    // Print the circular linked list
    print(tail);

    return 0;
}
