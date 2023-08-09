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

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

Node* buildTree() {
    int data;
    Node* root = NULL;

    printf("Enter the root element: ");
    scanf("%d", &data);
    root = createNode(data);

    printf("Enter the left child of %d (or -1 to skip): ", data);
    scanf("%d", &data);
    if (data != -1) {
        root->left = buildTree();
    }

    printf("Enter the right child of %d (or -1 to skip): ", data);
    scanf("%d", &data);
    if (data != -1) {
        root->right = buildTree();
    }

    return root;
}

int main() {
    Node* root = NULL;

    printf("Build the binary tree:\n");
    root = buildTree();

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
