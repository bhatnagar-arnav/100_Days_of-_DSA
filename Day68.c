/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

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

// Topological Sort using Kahn’s Algorithm
void topoSort(Graph* g) {
    int* indegree = (int*)calloc(g->n, sizeof(int));

    // Compute in-degree
    for (int u = 0; u < g->n; u++) {
        Node* temp = g->adj[u];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Queue for vertices with indegree 0
    int* queue = (int*)malloc(g->n * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < g->n; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    int count = 0;
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        Node* temp = g->adj[v];
        while (temp) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");

    if (count != g->n) {
        printf("Graph has a cycle, topological ordering not possible.\n");
    }

    free(queue);
    free(indegree);
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
