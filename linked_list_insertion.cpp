#include <iostream>
using namespace std;

class Node {
public:
    int data;     // Public data member
    Node* next;   // Public next pointer
    
    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to print the linked list
void print(Node* ptr) {
    while (ptr != NULL) {
        cout << "The element is: " << ptr->data << endl;
        ptr = ptr->next;  // Move to the next node
    }
}
// FUnction to insert at the begining of the linked list
// void insertionatstart(Node* &head , int value){
//     Node* newNode = new Node(value);
//     newNode ->next =  head;
//     head = newNode;

// }

void insertionatstart(Node* &head , int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

// Function to insert a node in between (after a specific position)
void insertInBetween(Node* &head, int value, int position) {
    Node* newNode = new Node(value);  // Create a new node with the given value
    
    // If the position is 0, we are essentially inserting at the head
    if (position == 0) {
        newNode->next = head;         // Link new node to the current head
        head = newNode;               // Update head to point to the new node
        return;
    }
    
    Node* temp = head;
    int count = 0;
    
    // Traverse the list to find the position where to insert
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If temp is not NULL, it means we are inserting at a valid position
    if (temp != NULL) {
        newNode->next = temp->next;   // Link new node to the next node
        temp->next = newNode;         // Link previous node to the new node
    } else {
        cout << "Position out of bounds." << endl;
        delete newNode;  // Free memory if position is invalid
    }

}

void insertatend(Node* &head, int value){
    Node* temp = new Node(value);
    Node * ptr;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = temp;
}

int main() {
    // Dynamically allocate memory for the nodes using the constructor
    Node* head = new Node(4);  // First node with data = 4
    Node* second = new Node(5);  // Second node with data = 5
    Node* third = new Node(6);  // Third node with data = 55

    // Link the nodes
    head->next = second;
    second->next = third;

    cout << "Original Linked List:\n";
    print(head);

    insertionatstart(head, 2);
    cout << "\nLinked List after insertion in start:\n";
    print(head);

    // Insert a node with value 20 at position 2 (in between second and third nodes)
    insertInBetween(head, 9, 2);
    cout << "\nLinked List after insertion in between:\n";
    print(head);

    cout << "\nLinked List after insertion in the end:\n";
    insertatend(head,3);
    print(head);

    // Free the allocated memory
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
