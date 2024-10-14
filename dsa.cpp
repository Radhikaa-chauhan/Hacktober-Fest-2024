#include <iostream>
using namespace std;

// Define a Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function for In-order traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function for Pre-order traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for Post-order traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    
    // Insert values into the BST
    for (int value : values) {
        root = insert(root, value);
    }

    // Search for a value
    int target = 15;
    if (search(root, target)) {
        cout << "Found " << target << " in the BST.\n";
    } else {
        cout << target << " not found in the BST.\n";
    }

    // Traverse the BST
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
