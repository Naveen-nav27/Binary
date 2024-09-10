#include <stdio.h>
#include <stdlib.h>

// Define the structure for the tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
void inorderTraversal(Node* root);

// Main function
int main() {
    Node* root = NULL;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print elements in sorted order using in-order traversal
    printf("In-order Traversal (Sorted Order): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform in-order traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);      // Visit left subtree
    printf("%d ", root->data);         // Visit root node
    inorderTraversal(root->right);     // Visit right subtree
}
