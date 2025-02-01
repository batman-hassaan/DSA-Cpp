#include <iostream>
using namespace std;

// struct node{
//     int data;
//     struct node * next;
// };

class node{
    public:
    int data;
    node *next;
    node(int value) {
        data = value;
        next = NULL;
    }
};

void print(node *ptr){
    while(ptr != NULL){
        cout<<"The value is: "<<ptr-> data<< endl;
        ptr = ptr-> next;
    }
}

int main() {
    // for struct 
    // node* head = new node();
    // node* second= new node;
    // node* third= new node;
    
    
    // head-> data = 4;
    // head -> next =second;

    // second-> data = 5;
    // second->next= third;

    // third -> data=  6;
    // third -> next=  NULL;
    
    // for class
    node* head = new node(4);
    node* second= new node(5);
    node* third= new node(6);

    head->next = second;
    second->next = third;
    
    print(head);

    delete head;
    delete second;
    delete third;
   
    

    return 0;
}