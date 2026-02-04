/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays. */


#include <stdio.h>

void reverseArray(int* nums, int n) {
    int left = 0;          
    int right = n - 1;     
    
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

int main() {
    int n;
    printf("Enter a number: \n");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    reverseArray(nums, n);
    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
    
    return 0;
}