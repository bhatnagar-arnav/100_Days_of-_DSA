/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
            if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

struct Pair {
    struct Node* node;
    int hd;
};

struct Map {
    int hd;
    int* values;
    int size;
    int capacity;
};

void addToMap(struct Map* maps, int* mapSize, int hd, int val) {
    for (int i = 0; i < *mapSize; i++) {
        if (maps[i].hd == hd) {
            if (maps[i].size == maps[i].capacity) {
                maps[i].capacity *= 2;
                maps[i].values = (int*)realloc(maps[i].values, maps[i].capacity * sizeof(int));
            }
            maps[i].values[maps[i].size++] = val;
            return;
        }
    }
    maps[*mapSize].hd = hd;
    maps[*mapSize].capacity = 10;
    maps[*mapSize].values = (int*)malloc(maps[*mapSize].capacity * sizeof(int));
    maps[*mapSize].values[0] = val;
    maps[*mapSize].size = 1;
    (*mapSize)++;
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;
    struct Pair queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct Pair){root, 0};
    struct Map maps[1000];
    int mapSize = 0;
    while (front < rear) {
        struct Pair p = queue[front++];
        addToMap(maps, &mapSize, p.hd, p.node->data);
        if (p.node->left) queue[rear++] = (struct Pair){p.node->left, p.hd - 1};
        if (p.node->right) queue[rear++] = (struct Pair){p.node->right, p.hd + 1};
    }
    for (int i = -1000; i <= 1000; i++) {
        for (int j = 0; j < mapSize; j++) {
            if (maps[j].hd == i) {
                for (int k = 0; k < maps[j].size; k++) {
                    printf("%d ", maps[j].values[k]);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, N);
    verticalOrder(root);
    return 0;
}