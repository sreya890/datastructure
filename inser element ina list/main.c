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


Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
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


Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return head;
    }
    if (position == 0 || head == NULL) {
        return insertAtBeginning(head, data);
    }
    Node* newNode = createNode(data);
    Node* current = head;
    int count = 0;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
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
    head = insertAtBeginning(head, 5);
    head = insertAtPosition(head, 15, 2);


    printf("List elements: ");
    displayList(head);

    return 0;
}

