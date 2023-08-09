#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
Typedef struct Node {
    Int data;
    Struct Node* prev;
    Struct Node* next;
} Node;
Typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;
Void initializedeque(Deque* deque) {
    Deque->front = NULL;
    Deque->rear = NULL;
}
Int isempty(Deque* deque) {
    Return deque->front == NULL;
}
Void insertfront(Deque* deque, int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    Newnode->data = data;
    Newnode->prev = NULL;
    Newnode->next = deque->front;
    If (isempty(deque)) {
        Deque->rear = newnode;
    } else {
        Deque->front->prev = newnode;
    }
  Deque->front = newnode;
}
Void insertrear(Deque* deque, int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    Newnode->data = data;
    Newnode->prev = deque->rear;
    Newnode->next = NULL;
    If (isempty(deque)) {
        Deque->front = newnode;
    } else {
        Deque->rear->next = newnode;
    }
 Deque->rear = newnode;
}
Int deletefront(Deque* deque) {
    If (isempty(deque)) {
        Printf("Error: Deque is empty.\n");
        Return -1;
    }
   Node* frontnode = deque->front;
    Int data = frontnode->data;
    Deque->front = frontnode->next;
    If (deque->front == NULL) {
        Deque->rear = NULL;
    } else {
        Deque->front->prev = NULL;
    }
    Free(frontnode);
    Return data;
}
Int deleterear(Deque* deque) {
    If (isempty(deque)) {
        Printf("Error: Deque is empty.\n");
        Return -1;
    }
    Node* rearnode = deque->rear;
    Int data = rearnode->data;
    Deque->rear = rearnode->prev;
    If (deque->rear == NULL) {
        Deque->front = NULL;
    } else {
        Deque->rear->next = NULL;
    }
    Free(rearnode);
    Return data;
}
Void displaydeque(Deque* deque) {
    If (isempty(deque)) {
        Printf("Deque is empty.\n");
        Return;
    }
    Node* current = deque->front;
    Printf("Deque: ");
    While (current != NULL) {
        Printf("%d ", current->data);
        Current = current->next;
    }
    Printf("\n");
}
Int main() {
    Deque deque;
    Initializedeque(&deque);
    Int choice, data;
    While (1) {
        Printf("\ndeque Operations:\n");
        Printf("1. Insert at front\n");
        Printf("2. Insert at rear\n");
        Printf("3. Delete from front\n");
        Printf("4. Delete from rear\n");
        Printf("5. Display the deque\n");
        Printf("6. Exit\n");
        Printf("Enter your choice: ");
        Scanf("%d", &choice);
        Switch (choice) {
            Case 1:
                Printf("Enter the element to insert at the front: ");
                Scanf("%d", &data);
                Insertfront(&deque, data);
                Break;
            Case 2:
                Printf("Enter the element to insert at the rear: ");
                Scanf("%d", &data);
                Insertrear(&deque, data);
                Break;
            Case 3:
                Data = deletefront(&deque);
                If (data != -1) {
                    Printf("Deleted element from the front: %d\n", data);
                }
                Break;
            Case 4:
                Data = deleterear(&deque);
                If (data != -1) {
                    Printf("Deleted element from the rear: %d\n", data);
                }
                Break;
            Case 5:
                Displaydeque(&deque);
                Break;
            Case 6:
                Printf("Exiting the program.\n");
                Exit(0);
            Default:
                Printf("Invalid choice. Please try again.\n");
        }
    }
    Return 0;
}

