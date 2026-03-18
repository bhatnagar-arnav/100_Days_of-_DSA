/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    int value = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)   // Queue became empty
        q->rear = NULL;

    free(temp);
    q->size--;

    enqueue(q, value);
    q->size--;             
}

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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
    int n, m, value;
    scanf("%d", &n);
    struct Queue* q = createQueue();
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);
    freeQueue(q);

    return 0;
}
