/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.
*/

#include <stdio.h>

void countingSort(int arr[], int n) {
    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // Frequency array
    int freq[max + 1];
    for (int i = 0; i <= max; i++) freq[i] = 0;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Prefix sums
    for (int i = 1; i <= max; i++) {
        freq[i] += freq[i - 1];
    }

    // Build output array (stable)
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // Copy back to original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
