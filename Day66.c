/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
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

// DFS utility for cycle detection
int dfsCycle(Graph* g, int v, int* visited, int* recStack) {
    visited[v] = 1;
    recStack[v] = 1;

    Node* temp = g->adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u] && dfsCycle(g, u, visited, recStack)) {
            return 1;
        } else if (recStack[u]) {
            return 1; // cycle found
        }
        temp = temp->next;
    }

    recStack[v] = 0; // backtrack
    return 0;
}

int hasCycle(Graph* g) {
    int* visited = (int*)calloc(g->n, sizeof(int));
    int* recStack = (int*)calloc(g->n, sizeof(int));

    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            if (dfsCycle(g, i, visited, recStack)) {
                free(visited);
                free(recStack);
                return 1;
            }
        }
    }

    free(visited);
    free(recStack);
    return 0;
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

    if (hasCycle(g)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
