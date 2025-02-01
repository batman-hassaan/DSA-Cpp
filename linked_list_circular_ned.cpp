#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* tail;

    CircularLinkedList() : tail(nullptr) {}

    void removeAfter(Node* node) {
        // Check if node is null or if the next field is null
        if (node == nullptr || node->next == nullptr) {
            return;
        }

        // If the list contains only one node
        if (node->next == node) {
            delete node; // Delete the single node
            tail = nullptr; // Set the tail to null
            return;
        }

        // Handle the case where the node to remove is the one after 'node'
        Node* nodeToRemove = node->next;
        node->next = nodeToRemove->next;

        // If the node to remove is the tail, update the tail
        if (nodeToRemove == tail) {
            tail = node; // Update the tail to the previous node
        }

        delete nodeToRemove; // Free memory of the removed node
    }

    // Utility functions for demonstration purposes
    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (tail == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* current = tail->next;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.addToEnd(1);
    cll.addToEnd(2);
    cll.addToEnd(3);
    cll.addToEnd(4);

    std::cout << "Original List: ";
    cll.display();

    // Remove the node after the second node (2)
    cll.removeAfter(cll.tail->next->next);

    std::cout << "After removeAfter: ";
    cll.display();

    return 0;
}
