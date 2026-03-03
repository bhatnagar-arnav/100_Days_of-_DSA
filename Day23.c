/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int arr1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n) {
        merged[k++] = arr1[i++];
    }
    while (j < m) {
        merged[k++] = arr2[j++];
    }
    for (int x = 0; x < n + m; x++) {
        printf("%d ", merged[x]);
    }

    return 0;
}