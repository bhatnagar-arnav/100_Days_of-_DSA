/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Insert at rear
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // Queue is empty, both front and rear point to new node
        q->front = q->rear = newNode;
        return;
    }

    // Link new node at rear and update rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
}

// Display queue from front to rear
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);       // Last element, no trailing space
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free all allocated memory
void freeQueue(struct Queue* q) {
    struct Node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    int n, value;
    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    display(q);
    freeQueue(q);

    return 0;
}