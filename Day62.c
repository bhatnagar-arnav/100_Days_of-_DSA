/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node** adj;  // array of adjacency list heads
    int n;       // number of vertices
} Graph;

Node* newNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) g->adj[i] = NULL;
    return g;
}

void addEdge(Graph* g, int u, int v) {
    Node* node = newNode(v);
    node->next = g->adj[u];
    g->adj[u] = node;

    node = newNode(u);
    node->next = g->adj[v];
    g->adj[v] = node;
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d:", i);
        Node* temp = g->adj[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    printGraph(g);

    return 0;
}
