/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/

#include <stdio.h>
int main()
{
    int n,x,flag=0,comp=0,loc;
     printf("Enter a number: \n");
        scanf("%d",&n);

     printf("Enter an array : \n");
     int  arr[n];
     for(int i=0;i<n;i++)
     {
        scanf("%d",&arr[i]);
     }
     printf("Enter a number to be searched: \n");
     scanf("%d",&x);
     for(int i=0;i<n;i++)
     {comp++;
        if(arr[i]==x )
        { loc=i;
          flag++;
         break;
        }
    }
    if(flag==0)
    printf("Not found");
    else
     {
       printf("Found at index %d\n",loc);
       printf("Comparisons %d\n",comp);    
     }
     return 0;
}