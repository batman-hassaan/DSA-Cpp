#include <iostream>
using namespace std;

// TreeNode class representing a single node in the binary tree
class TreeNode {
public:
    int value;             // Value of the node
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// BinaryTree class to manage tree operations
class BinaryTree {
private:
    TreeNode* root;        // Root of the binary tree

    // Recursive function for in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);        // Visit left child
            cout << node->value << " ";          // Process current node
            inOrderTraversal(node->right);       // Visit right child
        }else{
            cout << "The binary tree is empty.";
        }
    }

    // Recursive function for pre-order traversal
    void preOrderTraversal(TreeNode* node) {
        if(node != nullptr){
            cout<< node->value<< " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }else{
            cout << "The binary tree is empty.";
        }  
    }

    // Recursive function for post-order traversal
    void postOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);      // Visit left child
            postOrderTraversal(node->right);     // Visit right child
            cout << node->value << " ";          // Process current node
        }
        else{
            cout << "The binary tree is empty.";
        }
    }

public:
    // Constructor to initialize an empty binary tree
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a value into the binary tree
    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == nullptr) {
            root = newNode;  // If tree is empty, set root
            return;
        }

        // Use a queue to find the first available spot for insertion (level order)
        TreeNode* current = root;
        while (true) {
            if (val < current->value) {  // Go to the left
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {  // Go to the right
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }

    // Function to display in-order traversal
    void displayInOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    // Function to display pre-order traversal
    void displayPreOrder() {
        cout << "Pre-order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    // Function to display post-order traversal
    void displayPostOrder() {
        cout << "Post-order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
};

// Main function to demonstrate binary tree implementation
int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Display tree traversals
    tree.displayInOrder();      // Output: 3 5 7 10 12 15 18
    tree.displayPreOrder();     // Output: 10 5 3 7 15 12 18
    tree.displayPostOrder();    // Output: 3 7 5 12 18 15 10

    return 0;
}
