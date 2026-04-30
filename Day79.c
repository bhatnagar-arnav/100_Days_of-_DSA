/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Min-heap node
struct Node {
    int vertex;
    int dist;
};

// Min-heap structure
struct MinHeap {
    struct Node *nodes[MAX];
    int size;
};

void swap(struct Node **a, struct Node **b) {
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->nodes[idx]->dist < heap->nodes[parent]->dist) {
            swap(&heap->nodes[idx], &heap->nodes[parent]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(struct MinHeap *heap, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        smallest = idx;

        if (left < heap->size && heap->nodes[left]->dist < heap->nodes[smallest]->dist)
            smallest = left;
        if (right < heap->size && heap->nodes[right]->dist < heap->nodes[smallest]->dist)
            smallest = right;

        if (smallest != idx) {
            swap(&heap->nodes[idx], &heap->nodes[smallest]);
            idx = smallest;
        } else break;
    }
}

void push(struct MinHeap *heap, int v, int d) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->vertex = v;
    node->dist = d;
    heap->nodes[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

struct Node *pop(struct MinHeap *heap) {
    if (heap->size == 0) return NULL;
    struct Node *root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

int adj[MAX][MAX];
int n, m;

void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    struct MinHeap heap;
    heap.size = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct Node *node = pop(&heap);
        int u = node->vertex;
        free(node);

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !visited[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(&heap, v, dist[v]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    int src;
    scanf("%d", &src);

    dijkstra(src);
    return 0;
}

