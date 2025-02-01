#include <iostream>
using namespace std;

// Class for a doubly linked list node
class Node {
public:
    int data;     // Data in the node
    Node* next;   // Pointer to the next node
    Node* prev;   // Pointer to the previous node

    // Constructor to initialize the node
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Function to print the linked list in forward direction
void printForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "The element is: " << temp->data << endl;
        temp = temp->next;  // Move to the next node
    }
}

// Function to print the linked list in backward direction
void printBackward(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << "The element is: " << temp->data << endl;
        temp = temp->prev;  // Move to the previous node
    }
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node* &head, Node* &tail, int value) {
    Node* newNode = new Node(value);  // Create a new node
    if (head == NULL) {  // If the list is empty
        head = tail = newNode;  // The new node is both head and tail
        return;
    }
    // Insert at the beginning
    newNode->next = head;  // Link the new node to the current head
    head->prev = newNode;  // Link the current head back to the new node
    head = newNode;        // Update head to the new node
}

void insertAtPosition(Node* &head, Node* &tail, int key, int value) {
    // If inserting at the beginning
    if (key == 1) {
        insertAtBeginning(head, tail, value);  // Reuse existing function
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the node at position (key - 1)
    while (temp != NULL && count < key - 1) {
        temp = temp->next;
        count++;
    }

    // If key is beyond the list length
    if (temp == NULL) {
        cout << "Position " << key << " is invalid. Cannot insert." << endl;
        return;
    }

    // Insert the new node
    Node* newNode = new Node(value);
    Node* nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;

    if (nextNode != NULL) {
        nextNode->prev = newNode;  // Update the next node's previous pointer
    } else {
        // If inserting at the end, update the tail pointer
        tail = newNode;
    }
}



void insertend(Node *&tail, int val) {
    Node* newNode = new Node(val);  // Create a new node with the given value

    if (tail == NULL) {
        cout << "The previous node (tail) cannot be NULL." << endl;
        return;
    }
    // head->next = newNode;
    // newNode->prev = head;
    // newNode->next = nullptr;
    // head = newNode;

    // Set the pointers
    tail->next = newNode;    // Tail's next should point to the new node
    newNode->prev = tail;    // New node's prev should point to the old tail
    newNode->next = NULL;    // New node is now the new tail, so its next is NULL
    tail = newNode;          // Update the tail to point to the new node


}
int main() {
    // Initially, the list is empty
    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(head, tail, 10);  // Insert 10 at the beginning
    insertAtBeginning(head, tail, 20);  // Insert 20 at the beginning
    insertAtBeginning(head, tail, 30);  // Insert 30 at the beginning

    cout<<endl;
    // Print the list in forward direction
    cout << "List in forward direction:" << endl;
    printForward(head);

    cout<<endl;
    // Print the list in backward direction (starting from tail)
    cout << "List in backward direction:" << endl;
    printBackward(tail);

    // Insert a node between the first and second nodes
    insertAtPosition(head,tail,2, 25);  // Insert 25 between 30 and 20

    cout<<endl;
    // Print the list in forward direction
    cout << "List in forward direction after insertion between nodes:" << endl;
    printForward(head);

    cout<<endl;
    // Print the list in backward direction (starting from tail)
    cout << "List in backward direction after insertion between nodes:" << endl;
    printBackward(tail);

    // insertend(tail, 40);  // Insert 20 at the end
    // insertend(tail, 50);  // Insert 30 at the end

    // cout<<endl;
    // // Print the list in forward direction
    // cout << "List in forward direction after insertion at the end:" << endl;
    // printForward(head);

    // cout<<endl;
    // // Print the list in backward direction (starting from tail)
    // cout << "List in backward direction after insertion at the end:" << endl;
    // printBackward(tail);


    // Free the allocated memory
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
