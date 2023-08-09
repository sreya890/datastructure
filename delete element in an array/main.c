#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}


Node* deleteElement(Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    if (current->data == key) {
        head = current->next;
        free(current);
        return head;
    }
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list.\n");
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}


void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

        head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

        printf("List elements: ");
    displayList(head);


    head = deleteElement(head, 20);


    printf("Modified list elements: ");
    displayList(head);

    return 0;
}

