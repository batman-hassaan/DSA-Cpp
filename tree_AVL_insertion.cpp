#include <iostream>
using namespace std;

// Node class for AVL Tree
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// Get the height of a node
int getHeight(TreeNode* node) {
    return node ? node->height : 0;
}

// Get the balance factor of a node
int getBalance(TreeNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update the height of a node
void updateHeight(TreeNode* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Right rotation (LL case)
TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T = x->right;

    x->right = y;
    y->left = T;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation (RR case)
TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T = y->left;

    y->left = x;
    x->right = T;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balance the tree at the given node
TreeNode* balanceTree(TreeNode* node) {
    int balance = getBalance(node);

    // Left-heavy (LL or LR case)
    if (balance > 1) {
        if (getBalance(node->left) < 0) {
            // LR case: Perform Left Rotation on left child
            node->left = rotateLeft(node->left);
        }
        // LL case: Perform Right Rotation
        return rotateRight(node);
    }

    // Right-heavy (RR or RL case)
    if (balance < -1) {
        if (getBalance(node->right) > 0) {
            // RL case: Perform Right Rotation on right child
            node->right = rotateRight(node->right);
        }
        // RR case: Perform Left Rotation
        return rotateLeft(node);
    }

    return node; // Already balanced
}

// Insert a value into the AVL Tree
TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value); // Create a new node if tree is empty
    }

    if (value < root->value) {
        root->left = insert(root->left, value); // Insert in the left subtree
    } else if (value > root->value) {
        root->right = insert(root->right, value); // Insert in the right subtree
    } else {
        return root; // Duplicate values are not allowed in AVL Tree
    }

    updateHeight(root); // Update height of the current node
    return balanceTree(root); // Balance the node if required
}

// In-order traversal to display the tree
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

// Main function
int main() {
    TreeNode* root = nullptr;

    // Insert values into the AVL Tree
    root = insert(root, 10); // LL case
    root = insert(root, 20); // RR case
    root = insert(root, 30); // Causes imbalance (RR case)
    root = insert(root, 40); // Insert more values
    root = insert(root, 50); // Causes imbalance (RR case)
    root = insert(root, 25); // RL case

    cout << "AVL Tree after insertion (In-order): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
