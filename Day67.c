/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/

#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct {
    Node** adj;
    int n;
} Graph;

// Create new node
Node* newNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
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

// Add edge (u -> v) directed
void addEdge(Graph* g, int u, int v) {
    Node* node = newNode(v);
    node->next = g->adj[u];
    g->adj[u] = node;
}

// DFS utility
void dfsTopo(Graph* g, int v, int* visited, int* stack, int* top) {
    visited[v] = 1;

    Node* temp = g->adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfsTopo(g, temp->vertex, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[(*top)++] = v; // push to stack after exploring children
}

// Topological sort
void topoSort(Graph* g) {
    int* visited = (int*)calloc(g->n, sizeof(int));
    int* stack = (int*)malloc(g->n * sizeof(int));
    int top = 0;

    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            dfsTopo(g, i, visited, stack, &top);
        }
    }

    // Print stack in reverse order
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(stack);
    free(visited);
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

    topoSort(g);

    return 0;
}
