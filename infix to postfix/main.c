#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return (s->top == -1);
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return (s->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack* s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->stack[++(s->top)] = ch;
}

// Function to pop an element from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}

// Function to return the top element of the stack without removing it
char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[s->top];
}

// Function to determine the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (ch >= 'a' && ch <= 'z') {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid infix expression\n");
                exit(1);
            }
            pop(&stack); // Discard the '(' from the stack
        } else {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        if (peek(&stack) == '(') {
            printf("Invalid infix expression\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

