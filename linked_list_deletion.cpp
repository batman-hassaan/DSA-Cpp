#include <iostream>
using namespace std;

class Node {
public:
    int data;     // Public data member
    Node* next;   // Public next pointer
    
    // Constructor
    Node(int value) :data(value), next(nullptr) {}
};

// Function to print the linked list
void print(Node* ptr) {
    while (ptr != NULL) {
        cout << "The element is: " << ptr->data << endl;
        ptr = ptr->next;  // Move to the next node
    }
}

void deleteFirstNode(Node* &head){
    if(head == NULL){
        cout<< "The Linked list is empty.";

    }
    Node * p = head ;
    head= head ->next;
    delete p;

}

void deletethenodebtw(Node*&head,int position){
    Node * temp = head;

    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    // If the position is 0, we are deleting the first node
    if(position == 0){
        temp=head;
        head = head->next;
        delete temp;
    }
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If temp or temp->next is NULL, it means the position is invalid
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    Node* node = temp->next;
    temp->next = temp->next->next;
    delete node;
}


void deleteLastNode(Node* &head) {
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return;
    }

    // If the list has only one node, delete the head
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    // Node* temp = head;
    // while(temp->next->next!=NULL){
    //     temp = temp->next;
    // }
    // Node* lastNode = temp->next; // The last node to be deleted
    // temp->next = NULL;            // Set the next pointer of the second-to-last node to NULL
    // delete lastNode;              // Delete the last node
}
   
int main() {
    // Dynamically allocate memory for the nodes using the constructor
    Node* head = new Node(4);  // First node with data = 4
    Node* second = new Node(5);  // Second node with data = 5
    Node* third = new Node(6);  // third node with data = 5
    Node* fourth = new Node(7);  // fourth node with data = 6
    Node* fifth = new Node(8);  // fifth node with data = 7
    Node* sixth = new Node(9);  // sixth node with data = 8

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Original Linked List:\n";
    print(head);

    // Delete the first node
    deleteFirstNode(head);
    cout << "\nLinked List after deleting the first node:\n";
    print(head);

    // Delete the node at position 2
    deletethenodebtw(head,2);
    cout << "\nLinked List after deleting the node at position 2:\n";
    print(head);

    // Delete the last Node
    deleteLastNode(head);
    cout << "\nLinked List after deleting the last node:\n";
    print(head);

    // Free the remaining allocated memory
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}