#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node with data and null children
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Helper function for inserting a node in the BST
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }
    

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node != nullptr){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    // Constructor to initialize the BST with an empty root
    BinarySearchTree() {
        root = nullptr;
    }

    // Public insert function
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to perform inorder traversal
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    // Public function to search for a value
    bool search(int val){
        Node* ptr = root;
        while(ptr != nullptr){
            if(ptr->data == val){
                return true;
            }
            else if(val < ptr ->data){
                ptr = ptr->left;
            }
            else{
                ptr = ptr->right;
            }
        }
    }
};

int main() {
    BinarySearchTree bst;

    // Inserting nodes
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(1);
    bst.insert(9);
    bst.insert(12);
    bst.insert(10);


    // Display inorder traversal
    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    // Searching for a value
    int key = 10;
    if (bst.search(key)) {
        cout << "Found " << key << " in the tree." << endl;
    } else {
        cout << key << " not found in the tree." << endl;
    }

    return 0;
}
