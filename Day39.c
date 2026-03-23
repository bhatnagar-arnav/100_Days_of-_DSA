/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

static inline void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static inline int parent(int i) { return i >> 1; }
static inline int left  (int i) { return i << 1; }
static inline int right (int i) { return (i << 1) | 1; }

void heap_init(MinHeap *h) { h->size = 0; }

static void sift_up(MinHeap *h, int i) {
    while (i > 1 && h->data[parent(i)] > h->data[i]) {
        swap(&h->data[parent(i)], &h->data[i]);
        i = parent(i);
    }
}

static void sift_down(MinHeap *h, int i) {
    while (1) {
        int smallest = i;
        int l = left(i), r = right(i);
        if (l <= h->size && h->data[l] < h->data[smallest]) smallest = l;
        if (r <= h->size && h->data[r] < h->data[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
}

void insert(MinHeap *h, int val) {
    if (h->size >= MAX_SIZE - 1) {
        fprintf(stderr, "Heap overflow\n");
        return;
    }
    h->data[++h->size] = val;   
    sift_up(h, h->size);       
}

int extractMin(MinHeap *h) {
    if (h->size == 0) return -1;
    int min = h->data[1];          
    h->data[1] = h->data[h->size--]; 
    sift_down(h, 1);               
    return min;
}

int peek(const MinHeap *h) {
    return h->size == 0 ? -1 : h->data[1];
}
int main(void) {
    MinHeap h; heap_init(&h);

    int n; scanf("%d", &n);
    char op[20];

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x; scanf("%d", &x);
            insert(&h, x);

        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin(&h));

        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(&h));
        }
    }
    return 0;
}