/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/

#include <stdio.h>

int main() {
     int n ,pos;
     printf("Enter a number: \n");
     scanf("%d",&n);
     printf("Enter an array : \n");
     int  arr[n];
     for(int i=0;i<n;i++)
     {
        scanf("%d",&arr[i]);

     }
     printf("Enter position: \n");
     scanf("%d",&pos);
    int arr2[n-1];
   int j=0;
    for(int i=0;i<n-1;i++)
    {
        if(j==(pos-1)){
       j++;
        }
        arr2[i]=arr[j];
          j++;
        
    }
    for(int i=0;i<n-1;i++){
    printf("%d ", arr2[i]);
    }
    return 0;
}