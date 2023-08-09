#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Deque {
    struct Node* front;
    struct Node* rear;
    int capacity;
    int size;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


struct Deque* createDeque(int capacity) {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->capacity = capacity;
    deque->size = 0;
    return deque;
}


int isEmpty(struct Deque* deque) {
    return deque->size == 0;
}


int isFull(struct Deque* deque) {
    return deque->size == deque->capacity;
}

void insertFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    deque->size++;
    printf("Element %d inserted at the front of the deque.\n", data);
}


void insertRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert element.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    deque->size++;
    printf("Element %d inserted at the rear of the deque.\n", data);
}


void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        return;
    }

    struct Node* temp = deque->front;

    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    int data = temp->data;
    free(temp);

    deque->size--;
    printf("Element %d deleted from the front of the deque.\n", data);
}


void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete element.\n");
        return;

