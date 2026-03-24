/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;   
    Node *rear;    
    int   size;
} Queue;

void queue_init(Queue *q) {
    q->front = q->rear = NULL;
    q->size  = 0;
}

void enqueue(Queue *q, int val) {
    Node *n = malloc(sizeof(Node));
    if (!n) { fprintf(stderr, "malloc failed\n"); exit(1); }
    n->data = val;
    n->next = NULL;

    if (q->rear == NULL) {          
        q->front = q->rear = n;
    } else {
        q->rear->next = n;          
        q->rear       = n;          
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) return -1;

    Node *tmp  = q->front;
    int   val  = tmp->data;

    q->front   = q->front->next;
    if (q->front == NULL)          
        q->rear = NULL;

    free(tmp);
    q->size--;
    return val;
}

int main(void) {
    Queue q; queue_init(&q);

    int n; scanf("%d", &n);
    char op[20];

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int x; scanf("%d", &x);
            enqueue(&q, x);

        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(&q));
        }
    }

    while (q.front) dequeue(&q);
    return 0;
}