/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
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

// BFS using queue
void bfs(Graph* g, int s) {
    int* visited = (int*)calloc(g->n, sizeof(int));
    int* queue = (int*)malloc(g->n * sizeof(int));
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        Node* temp = g->adj[v];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    free(queue);
    free(visited);
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

    bfs(g, s);

    return 0;
}
