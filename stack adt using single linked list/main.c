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


typedef struct Stack {
    Node* top;
} Stack;


void initializeStack(Stack* stack) {
    stack->top = NULL;
}


int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}


void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}


int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack->top->data;
}


void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);


    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);


    displayStack(&stack);


    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);


    displayStack(&stack);


    int topElement = peek(&stack);
    printf("Top element: %d\n", topElement);

    return 0;
}

