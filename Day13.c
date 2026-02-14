/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9
*/
#include<stdio.h>
#include<stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  *returnSize = matrixSize * (*matrixColSize);
  int* arr = (int*)malloc((*returnSize) * sizeof(int));
   int k=0,top=0,left=0,right=*matrixColSize-1,bottom=matrixSize-1;
   while(top<=bottom && left<=right)
   {
    for(int i=left;i<=right;i++)
      {arr[k++]=matrix[top][i];
      }top++;
    for(int i=top;i<=bottom;i++)
     {arr[k++]=matrix[i][right];
     }right--;
    if(top<=bottom)
    {
        for(int i=right;i>=left;i--)
        arr[k++]=matrix[bottom][i];
          bottom--;          
    } 
    if(left<=right)
    {
        for(int i=bottom;i>=top;i--)
     {   arr[k++]=matrix[i][left];
    }left++;
    }
   }
   return arr;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int** matrix = (int**)malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int returnSize;
    int* result = spiralOrder(matrix, r, &c, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    for(int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}