#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000  // Maximum size of the queue

class Queue {
private:
    int front, rear;  // Pointers for front and rear
    int arr[MAX];     // Array to store the queue elements

public:
    // Constructor to initialize the queue
    Queue() {
        front = rear = -1;  // Queue is initially empty
    }

    // Function to add an element to the queue
    bool enqueue(int x) {
        if (rear == MAX - 1) {  // Check if the queue is full
            cout << "Queue Overflow" << endl;
            return false;
        } else {
            if (front == -1) front = 0;  // Set front when the first element is added
            arr[++rear] = x;
            cout << x << " enqueued to queue" << endl;
            return true;
        }
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (front == -1 || front > rear) {  // Check if the queue is empty
            cout << "Queue Underflow" << endl;
            return -1;
        } else {
            int x = arr[front++];
            if (front > rear) front = rear = -1;  // Reset the queue if it's empty
            return x;
        }
    }

    // Function to get the front element
    int getFront() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }
    void display(){
        if(front == -1){
            cout<<"Queue is empty";
        }
        else{
            cout<<"The elements in the queues are: ";
            for(int i = front; i <= rear; i++){
                cout<<arr[i] << ", ";
            }
        }
    }
};

// Driver code
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.dequeue() << " dequeued from queue" << endl;

    cout << "Front element is " << queue.getFront() << endl;
    cout << "Queue empty: " << (queue.isEmpty() ? "Yes" : "No") << endl;

    queue.display();

    return 0;
}
