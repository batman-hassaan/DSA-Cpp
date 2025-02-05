#include <iostream>

// Node structure
class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data (val) , next(nullptr) {}
};

// Class for Queue using Linked List
class Queue {
private:
    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor to initialize front and rear
    Queue() {
        front = rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        // Create a new node
        Node* temp = new Node(value);
        // temp->data = value;
        temp->next = nullptr;

        // If the queue is empty, the new node becomes front and rear
        if (isEmpty()) {
            front = rear = temp;
            std::cout << value << " enqueued to queue\n";
        } else {
            // Add the new node at the end of the queue
            rear->next = temp;
            rear = temp;
            std::cout << value << " enqueued to queue\n";
        }
    }

    // Function to remove an element from the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        } else {
            Node* temp = front;  // Store the current front node
            front = front->next; // Move front to the next node

            if (front == nullptr) {
                // If front becomes nullptr, the queue is empty
                rear = nullptr;
            }

            int dequeuedValue = temp->data;
            delete temp;  // Free memory of the dequeued node
            return dequeuedValue;
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        } else {
            return front->data;
        }
    }

    // Function to display all the elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        } else {
            Node* temp = front;
            std::cout << "Queue elements: ";
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
};

// Driver code
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    std::cout << queue.dequeue() << " dequeued from queue\n";

    queue.display();

    std::cout << "Front element is: " << queue.peek() << std::endl;

    return 0;
}
