#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value node in a binary search tree
struct Node* findMinNode(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // If the data is less than the root node, search in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data is greater than the root node, search in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If the data is equal to the root node, delete the root
    else {
        // Case 1: No child or 1 child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: 2 children
        else {
            struct Node* minNode = findMinNode(root->right);
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    return root;
}

// Function to print the binary search tree in in-order traversal
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary search tree before deletion
    printf("Binary search tree before deletion: ");
    inOrderTraversal(root);
    printf("\n");

    // Delete an element from the binary search tree
    int dataToDelete = 30;
    root = deleteNode(root, dataToDelete);
    printf("Element %d deleted from the binary search tree.\n", dataToDelete);

    // Print the binary search tree after deletion
    printf("Binary search tree after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}



