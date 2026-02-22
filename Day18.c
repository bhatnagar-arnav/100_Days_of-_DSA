/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/
#include<stdio.h>
#include<stdlib.h>
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;
    k = k % numsSize; 
    int* temp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
    free(temp);
}
int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    rotate(arr, n, k);

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
