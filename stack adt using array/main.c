#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}


int isEmpty(Stack* s) {
    return (s->top == -1);
}

int isFull(Stack* s) {
    return (s->top == MAX_SIZE - 1);
}


void push(Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->stack[++(s->top)] = val;
}


int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}


int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[s->top];
}

int main() {
    Stack stack;
    initialize(&stack);


    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);


    printf("Top element: %d\n", peek(&stack));


    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));


    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}

