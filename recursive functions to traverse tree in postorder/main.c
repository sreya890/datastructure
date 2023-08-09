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

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    int value;

    printf("Build the binary tree:\n");
    printf("Enter the root element: ");
    scanf("%d", &value);
    root = createNode(value);

    printf("Enter the left child of %d (or -1 to skip): ", value);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping left child for brevity
    }

    printf("Enter the right child of %d (or -1 to skip): ", value);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping right child for brevity
    }

    printf("Enter the left child of %d (or -1 to skip): ", root->data);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping left child for brevity
    }

    printf("Enter the left child of %d (or -1 to skip): ", value);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping left child for brevity
    }

    printf("Enter the right child of %d (or -1 to skip): ", value);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping right child for brevity
    }

    printf("Enter the right child of %d (or -1 to skip): ", root->data);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping right child for brevity
    }

    printf("Enter the left child of %d (or -1 to skip): ", value);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping left child for brevity
    }

    printf("Enter the right child of %d (or -1 to skip): ", value);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping right child for brevity
    }

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

