/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the length of the longest subarray with sum 0
int longestZeroSumSubarray(int arr[], int n) {
    int maxLen = 0;
    int sum = 0;

    // Hash map implemented using arrays (sum -> first index)
    // For simplicity, we use a large array with offset
    int offset = 100000; // to handle negative sums
    int size = 2 * offset + 1;
    int *map = (int *)malloc(size * sizeof(int));

    // Initialize map with -2 (meaning not seen)
    for (int i = 0; i < size; i++) {
        map[i] = -2;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int idx = sum + offset;
        if (map[idx] == -2) {
            map[idx] = i; // store first occurrence
        } else {
            int len = i - map[idx];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    free(map);
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSumSubarray(arr, n));
    return 0;
}

