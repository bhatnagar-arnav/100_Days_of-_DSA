/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/

#include <stdio.h>

int main() {
     int n ,pos,x;
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
     printf("Enter element to insert: \n");
     scanf("%d",&x);
    int arr2[n+1];
    int j=0;
    for(int i=0;i<n+1;i++)
    {
        if(i==(pos-1)){
        arr2[i]=x;
        arr2[i+1]=arr[i];
        
       }
        else{
            arr2[i]=arr[j];
            j++;
        }
    }
    for(int i=0;i<n+1;i++){
    printf("%d", arr2[i]);
    }
    return 0;
}