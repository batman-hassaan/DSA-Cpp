#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val) : data(val) , next(nullptr) {}
};
void print(node* ptr){
    while(ptr != nullptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
void insertstart(node* &head , int val){
    node* ptr = new node(val);
    ptr->next = head;
    head = ptr ;
}

void insertbtw(node* head,int val,int position){
    node* newNode = new node(val);
    if(position == 0 ){
        newNode->next = head;         // Link new node to the current head
        head = newNode;               // Update head to point to the new node
        return; 
    }
    node*ptr = head;
    int i = 0;
    while(i < position-1 && ptr!= nullptr){
        ptr = ptr->next;
        i++;
    }

    if(ptr != nullptr)
    {newNode->next = ptr->next;
    ptr->next = newNode;}
    else{
        cout << "the linked list doesnot have an position"<<position;
    }
}

void insertend(node* &head ,int val){
    node* ptr = new node(val);
    node* temp = head;
    while(temp ->next != nullptr){
        temp = temp->next;
    }
    temp ->next = ptr;
}

int main(){
    node* n1 = new node(6);
    node* n2 = new node(9);
    node* n3 = new node(15);

    n1->next = n2;
    n2->next = n3;

    insertstart(n1,5);
    insertbtw(n1,7,2);
    insertend(n1,20);

    print(n1);
}