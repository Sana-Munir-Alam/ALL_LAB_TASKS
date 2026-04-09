#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Automatically insert based on ID (BST-style)
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } else {
        cout << "Duplicate ID (" << val << ") ignored.\n";
    }
    return root;
}

// Returns height if balanced, -1 if unbalanced
int checkHeight(Node* root) {
    if (!root) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isSystemBalanced(Node* root) {
    return checkHeight(root) != -1;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;
    int val, choice;

    cout << "Create your folder (binary tree) structure:\n";
    cout << "Enter root folder ID: ";
    cin >> val;
    root = new Node(val);

    do {
        cout << "\nEnter subfolder ID to insert: ";
        cin >> val;
        root = insert(root, val);
        cout << "Do you want to insert another folder? (1 = Yes, 0 = No): ";
        cin >> choice;
    } while (choice == 1);

    cout << "\nInorder traversal of Folder Structure: ";
    inorder(root);
    cout << "\nPreorder traversal (structure view): ";
    preorder(root);
    cout << endl;

    // Check balance
    if (isSystemBalanced(root)) {
        cout << "\nThe folder system is balanced.\n";
    }else { 
        cout << "\nThe folder system is NOT balanced.\n"; 
    }
    return 0;
}
