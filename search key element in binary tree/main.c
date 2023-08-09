#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchNode(root->left, key);
    }
    else {
        return searchNode(root->right, key);
    }
}

int main() {
    Node* root = NULL;

    int numElements;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    Node* searchResult = searchNode(root, key);

    if (searchResult != NULL) {
        printf("Element %d is found in the BST.\n", key);
    }
    else {
        printf("Element %d is not found in the BST.\n", key);
    }

    return 0;
}
