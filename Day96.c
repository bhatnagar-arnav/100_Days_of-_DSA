/*Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].
*/

#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray index
    int j = mid + 1;  // right subarray index
    int k = left;     // temp array index
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // all remaining left elements are inversions
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    long long inversions = mergeSort(arr, temp, 0, n - 1);
    printf("%lld\n", inversions);

    return 0;
}
