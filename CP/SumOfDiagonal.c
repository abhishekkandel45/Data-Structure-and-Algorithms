/* Given the Square matrix, calculate the absolute difference between the sums of its diagonals. 

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("Enter the size of the square Matrix\n");
    int n;
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)  
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int primarySum=0;
    int secondarySum=0;
    for(int i=0;i<n;i++)
    {
        primarySum+=arr[i][i];
        secondarySum+=arr[i][n-i-1];
    }
    printf ("Primary Sum is %d\n",primarySum);
    printf ("Secondary Sum is %d\n",secondarySum);
    int diff=abs(primarySum-secondarySum); 
    printf("The absolute difference is %d\n",diff);
    return 0;
}

