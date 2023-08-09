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

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
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
        root->left = createNode(value);

        printf("Enter the left child of %d (or -1 to skip): ", value);
        scanf("%d", &value);
        if (value != -1) {
            root->left->left = createNode(value);

            printf("Enter the left child of %d (or -1 to skip): ", value);
            scanf("%d", &value);
            if (value != -1) {
                // Skipping nested left child for brevity
            }

            printf("Enter the right child of %d (or -1 to skip): ", value);
            scanf("%d", &value);
            if (value != -1) {
                // Skipping nested right child for brevity
            }
        }

        printf("Enter the right child of %d (or -1 to skip): ", value);
        scanf("%d", &value);
        if (value != -1) {
            // Skipping right child for brevity
        }
    }

    printf("Enter the right child of %d (or -1 to skip): ", root->data);
    scanf("%d", &value);
    if (value != -1) {
        // Skipping right child for brevity
    }

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
