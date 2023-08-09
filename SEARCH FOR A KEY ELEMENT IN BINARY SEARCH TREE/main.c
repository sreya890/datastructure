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

// Function to insert a new element into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node and make it the root
        return createNode(data);
    }

    // If the data is less than the root node, insert it in the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If the data is greater than or equal to the root node, insert it in the right subtree
    else if (data >= root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a key element in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    // If the key is less than the root node, search in the left subtree
    if (key < root->data) {
        return search(root->left, key);
    }
    // If the key is greater than the root node, search in the right subtree
    else {
        return search(root->right, key);
    }
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

    // Print the binary search tree
    printf("In-order traversal of the binary search tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for a key element in the binary search tree
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the binary search tree.\n", key);
    } else {
        printf("Element %d not found in the binary search tree.\n", key);
    }

    return 0;
}
