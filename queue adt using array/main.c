#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int queue[MAX_SIZE];
    int front;
    int rear;
} Queue;


void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}


int isFull(Queue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}


void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        exit(1);
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->queue[q->rear] = val;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int val = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return val;
}


int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return q->queue[q->front];
}

int main() {
    Queue queue;
    initialize(&queue);


    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);


    printf("Front element: %d\n", front(&queue));


    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Is the queue empty? %s\n", isEmpty(&queue) ? "Yes" : "No");

    return 0;
}

