#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
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
void push(Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->stack[++(s->top)] = val;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->stack[(s->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    Stack stack;
    initialize(&stack);

    int i;
    int operand1, operand2;
    int result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert character to integer
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}

