/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

// Bellman-Ford Algorithm
void bellmanFord(Edge* edges, int n, int m, int src) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    // Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("Vertex %d: INF\n", i);
        else printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, m, src;
    scanf("%d %d", &n, &m);

    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &src);

    bellmanFord(edges, n, m, src);

    free(edges);
    return 0;
}
