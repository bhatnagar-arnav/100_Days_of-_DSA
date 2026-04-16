#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, u, v, directed;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if (!directed) {
            adj[v][u] = 1; // For undirected graph
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
