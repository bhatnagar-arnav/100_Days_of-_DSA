/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *front, *back;
    int size;
} Deque;

static Node *new_node(int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val; n->prev = n->next = NULL;
    return n;
}

void deque_init(Deque *d)         { d->front = d->back = NULL; d->size = 0; }
int  deque_empty(const Deque *d)  { return d->size == 0; }
int  deque_size(const Deque *d)   { return d->size; }

void push_front(Deque *d, int val) {
    Node *n = new_node(val);
    if (deque_empty(d)) { d->front = d->back = n; }
    else { n->next = d->front; d->front->prev = n; d->front = n; }
    d->size++;
}

void push_back(Deque *d, int val) {
    Node *n = new_node(val);
    if (deque_empty(d)) { d->front = d->back = n; }
    else { n->prev = d->back; d->back->next = n; d->back = n; }
    d->size++;
}

int pop_front(Deque *d) {
    if (deque_empty(d)) { fprintf(stderr, "pop_front: empty\n"); return -1; }
    Node *n = d->front; int val = n->data;
    d->front = n->next;
    if (d->front) d->front->prev = NULL; else d->back = NULL;
    free(n); d->size--;
    return val;
}

int pop_back(Deque *d) {
    if (deque_empty(d)) { fprintf(stderr, "pop_back: empty\n"); return -1; }
    Node *n = d->back; int val = n->data;
    d->back = n->prev;
    if (d->back) d->back->next = NULL; else d->front = NULL;
    free(n); d->size--;
    return val;
}

int front(const Deque *d) {
    if (deque_empty(d)) { fprintf(stderr, "front: empty\n"); return -1; }
    return d->front->data;
}

int back(const Deque *d) {
    if (deque_empty(d)) { fprintf(stderr, "back: empty\n"); return -1; }
    return d->back->data;
}

void deque_clear(Deque *d) {
    while (!deque_empty(d)) pop_front(d);
}

int deque_erase(Deque *d, int idx) {
    if (idx < 0 || idx >= d->size) { fprintf(stderr, "erase: out of range\n"); return -1; }
    if (idx == 0)          return pop_front(d);
    if (idx == d->size - 1) return pop_back(d);
    Node *cur = d->front;
    for (int i = 0; i < idx; i++) cur = cur->next;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    int val = cur->data; free(cur); d->size--;
    return val;
}

void deque_swap(Deque *a, Deque *b) {
    Deque tmp = *a; *a = *b; *b = tmp;
}
void emplace_front(Deque *d, int val) { push_front(d, val); }
void emplace_back (Deque *d, int val) { push_back (d, val); }

void deque_resize(Deque *d, int new_size) {
    while (d->size > new_size) pop_back(d);
    while (d->size < new_size) push_back(d, 0);
}

void deque_assign(Deque *d, int count, int val) {
    deque_clear(d);
    for (int i = 0; i < count; i++) push_back(d, val);
}

void deque_reverse(Deque *d) {
    Node *lo = d->front, *hi = d->back;
    int half = d->size / 2;
    for (int i = 0; i < half; i++) {
        int tmp = lo->data; lo->data = hi->data; hi->data = tmp;
        lo = lo->next; hi = hi->prev;
    }
}

void deque_sort(Deque *d) {
    if (d->size < 2) return;
    for (Node *i = d->front->next; i; i = i->next) {
        int key = i->data;
        Node *j = i->prev;
        while (j && j->data > key) { j->next->data = j->data; j = j->prev; }
        (j ? j->next : d->front)->data = key;
    }
}

void deque_print(const Deque *d) {
    printf("Deque [size=%d]: front -> ", d->size);
    for (Node *n = d->front; n; n = n->next)
        printf("%d%s", n->data, n->next ? " <-> " : "");
    if (deque_empty(d)) printf("(empty)");
    printf(" <- back\n");
}

int main(void) {
    Deque d; deque_init(&d);

    printf("=== push_back: 10 20 30 ===\n");
    push_back(&d, 10); push_back(&d, 20); push_back(&d, 30);
    deque_print(&d);

    printf("\n=== push_front: 5, then 1 ===\n");
    push_front(&d, 5); push_front(&d, 1);
    deque_print(&d);

    printf("\n=== front=%d  back=%d  size=%d ===\n",
           front(&d), back(&d), deque_size(&d));

    printf("\n=== pop_front -> %d ===\n", pop_front(&d));
    printf("=== pop_back  -> %d ===\n", pop_back(&d));
    deque_print(&d);

    printf("\n=== erase index 1 -> %d ===\n", deque_erase(&d, 1));
    deque_print(&d);

    printf("\n=== emplace_back 99, emplace_front 0 ===\n");
    emplace_back(&d, 99); emplace_front(&d, 0);
    deque_print(&d);

    printf("\n=== reverse ===\n");
    deque_reverse(&d); deque_print(&d);

    printf("\n=== sort ===\n");
    deque_sort(&d); deque_print(&d);

    printf("\n=== resize to 6 (pad with 0) ===\n");
    deque_resize(&d, 6); deque_print(&d);

    printf("\n=== assign: 4 copies of 7 ===\n");
    deque_assign(&d, 4, 7); deque_print(&d);

    printf("\n=== swap with a fresh deque {100,200} ===\n");
    Deque d2; deque_init(&d2);
    push_back(&d2, 100); push_back(&d2, 200);
    deque_swap(&d, &d2);
    printf("d  : "); deque_print(&d);
    printf("d2 : "); deque_print(&d2);

    printf("\n=== clear both ===\n");
    deque_clear(&d); deque_clear(&d2);
    printf("d  empty? %s\n", deque_empty(&d)  ? "yes" : "no");
    printf("d2 empty? %s\n", deque_empty(&d2) ? "yes" : "no");

    return 0;
}