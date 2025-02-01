#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node *next;

        Node( int val) : value(val), next(nullptr) {}
};

void print(Node* root){
    while(root){
        cout<< root->value << " ";
        root = root->next;
    }
}

int main() {
    Node* head = new Node(4);
    Node* first = new Node(5);
    Node* second = new Node(7);

    head->next =first;
    first ->next =second ;

    print(head);

    delete head;
    delete second;
    delete first;
    return 0;
}