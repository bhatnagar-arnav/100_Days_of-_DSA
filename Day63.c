/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
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

// Add edge (u, v) undirected
void addEdge(Graph* g, int u, int v) {
    Node* node = newNode(v);
    node->next = g->adj[u];
    g->adj[u] = node;

    node = newNode(u);
    node->next = g->adj[v];
    g->adj[v] = node;
}

// Recursive DFS
void dfs(Graph* g, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = g->adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(g, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    scanf("%d", &s);

    int* visited = (int*)calloc(n, sizeof(int));
    dfs(g, s, visited);

    return 0;
}
