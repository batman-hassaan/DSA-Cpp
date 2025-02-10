#include <iostream>
using namespace std;
#define MAX 4  // Define the maximum size of the stack

class Stack {
private:
    int top;         // Variable to track the index of the top element
    int arr[MAX];    // Array to store stack elements

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;    // Stack is empty initially, so set top to -1
    }

    // Function to add an element to the stack
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
            return false;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack" <<endl;
            return true;
        }
    }

    // Function to remove an element from the stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    // Function to return the top element of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};

// Driver code
int main() {
    Stack stack;  // Create a stack object

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << stack.pop() << " popped from stack" << endl;

    cout << "Top element is " << stack.peek() << endl;

    cout << "Stack empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0 ;
}