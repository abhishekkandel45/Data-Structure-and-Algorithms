/*
Using Kadan's Algorithm
Find the Maximum Sum of a subarray in an array
*/

#include <stdio.h>
#include <stdlib.h>

int max_sum(int *arr, int size)
{
    int max_so_far = 0;
    int max_ending_here = 0;
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }
}

//Driver Code

int main()
{
    printf ("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int max = max_sum(arr, size);
    printf("The maximum sum of the subarray is: %d\n", max);
    return 0;
}