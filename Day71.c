/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
    int* table;
    int size;
} HashTable;

// Simple hash function
int hash(int key, int m) {
    return key % m;
}

// Create hash table
HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) ht->table[i] = EMPTY;
    return ht;
}

// Insert using quadratic probing
void insert(HashTable* ht, int key) {
    int m = ht->size;
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (ht->table[pos] == EMPTY) {
            ht->table[pos] = key;
            return;
        }
    }
    // Table full (not expected in sample)
}

// Search using quadratic probing
int search(HashTable* ht, int key) {
    int m = ht->size;
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (ht->table[pos] == EMPTY) return 0; // not found
        if (ht->table[pos] == key) return 1;   // found
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    HashTable* ht = createTable(m);

    for (int i = 0; i < q; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(ht, key)) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}
