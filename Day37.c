/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <stdio.h>
#include <string.h>

#define MAX 100000

int heap[MAX];
int size = 0;

static inline void swap(int i, int j) {
    int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

static void siftUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(parent, i);
            i = parent;
        } else break;
    }
}

static void siftDown(int i) {
    while (1) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left  < size && heap[left]  < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest == i) break;
        swap(i, smallest);
        i = smallest;
    }
}

void insert(int x) {
    heap[size++] = x;
    siftUp(size - 1);
}

void delete() {
    if (size == 0) { printf("-1\n"); return; }
    printf("%d\n", heap[0]);
    heap[0] = heap[--size];   
    siftDown(0);
}

void peek() {
    if (size == 0) { printf("-1\n"); return; }
    printf("%d\n", heap[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') {          
            int x; scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') {   
            delete();
        } else {                      
            peek();
        }
    }
    return 0;
}