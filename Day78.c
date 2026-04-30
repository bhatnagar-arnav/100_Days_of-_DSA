/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#include <limits.h>

#define MAX 1000

int adj[MAX][MAX];
int n, m;

int primMST() {
    int parent[MAX];   // store MST
    int key[MAX];      // minimum weight edge to connect
    int inMST[MAX];    // included in MST

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    key[1] = 0; // start from vertex 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        // pick minimum key vertex not yet in MST
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = 1;
        totalWeight += key[u];

        // update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}
