/*
Date: 2023/07/24
Lab 1
Insertion Sort Algorithm
*/

/* Alogthim

insertion =sort(A)
{
    for j=2 to A
    {
        key = A[j]
        i = j-1
        while (i>0 and A[i]>key)
        {
            A[i+1] = A[i]
            i = i-1
        }
        A[i+1] = key
    }
}

*/


#include <stdio.h>
#include <stdlib.h>
 
 int main()
 {
    int A, i, j, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &A);
    //Declaring the Arry now A[]
    int A[];
    printf("Enter the elements of the array: ");
    for (i=0; i<A; i++)
    {
        scanf("%d", &A[i]);
    }
    for (j=2; j<A; j++)
    {
        key = A[j];
// Insert A[j] into sorte
        i = j-1;
        while (i>0 && A[i]>key)
        {
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
    printf("The sorted array is: ");
    for (i=0; i<A; i++)
    {
        printf("%d", A[i]);
    }
    return 0;
    }


