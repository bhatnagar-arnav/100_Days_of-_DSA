/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix
*/

#include <stdio.h>
int main() {
    int m,flag=1;
    scanf("%d",&m);
    int matrix1[m][m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
           scanf("%d", &matrix1[i][j]);
        }
    }
for(int i=0;i<m;i++)
{
    for(int j=0;j<m;j++)
    {
    if (i==j && matrix1[i][j]!=1)
    {  flag=0;
      break;
    }
    else if(i!=j && matrix1[i][j]!=0){
        flag=0;
        break;
    }
}
    if(!flag)
    break;
}
if(flag)
printf("Identity Matrix");
else
printf("Not a Identity Matrix");
    
    return 0;
}