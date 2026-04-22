/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node for adjacency list
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

// Graph structure
typedef struct {
    Node** adj;
    int n;
} Graph;

// Min-heap node
typedef struct {
    int vertex, dist;
} HeapNode;

// Min-heap structure
typedef struct {
    HeapNode* arr;
    int size;
    int capacity;
    int* pos; // position of vertex in heap
} MinHeap;

// Create new adjacency node
Node* newNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = NULL;
    return node;
}

// Initialize graph
Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) g->adj[i] = NULL;
    return g;
}

// Add edge (u -> v) directed with weight w
void addEdge(Graph* g, int u, int v, int w) {
    Node* node = newNode(v, w);
    node->next = g->adj[u];
    g->adj[u] = node;
}

// Swap heap nodes
void swapHeapNode(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
        smallest = left;
    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode smallestNode = heap->arr[smallest];
        HeapNode idxNode = heap->arr[idx];

        heap->pos[smallestNode.vertex] = idx;
        heap->pos[idxNode.vertex] = smallest;

        swapHeapNode(&heap->arr[smallest], &heap->arr[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract min
HeapNode extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        HeapNode dummy = {-1, INT_MAX};
        return dummy;
    }

    HeapNode root = heap->arr[0];
    HeapNode lastNode = heap->arr[heap->size - 1];
    heap->arr[0] = lastNode;

    heap->pos[root.vertex] = heap->size - 1;
    heap->pos[lastNode.vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Decrease key
void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->arr[i].dist = dist;

    while (i && heap->arr[i].dist < heap->arr[(i - 1) / 2].dist) {
        heap->pos[heap->arr[i].vertex] = (i - 1) / 2;
        heap->pos[heap->arr[(i - 1) / 2].vertex] = i;
        swapHeapNode(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if heap is empty
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// Dijkstra’s Algorithm
void dijkstra(Graph* g, int src) {
    int V = g->n;
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->pos = (int*)malloc(V * sizeof(int));
    heap->size = V;
    heap->capacity = V;
    heap->arr = (HeapNode*)malloc(V * sizeof(HeapNode));

    for (int v = 0; v < V; v++) {
        heap->arr[v].vertex = v;
        heap->arr[v].dist = dist[v];
        heap->pos[v] = v;
    }

    while (!isEmpty(heap)) {
        HeapNode minNode = extractMin(heap);
        int u = minNode.vertex;

        Node* temp = g->adj[u];
        while (temp) {
            int v = temp->vertex;
            if (heap->pos[v] < heap->size && dist[u] != INT_MAX &&
                temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Distance = %d\n", i, dist[i]);
    }

    free(heap->arr);
    free(heap->pos);
    free(heap);
}

int main() {
    int n, m, src;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(g, u, v, w);
    }

    scanf("%d", &src);

    dijkstra(g, src);

    return 0;
}
