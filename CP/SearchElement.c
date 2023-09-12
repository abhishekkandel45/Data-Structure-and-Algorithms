// Given an Interger array arr, find the contiguous subarray (containing at least one number)
// which has the largest sum and return its sum abs print the subarray.

#include <stdio.h>
#include <stdlib.h>

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
    int max = arr[0];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (sum > max) {
            max = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    printf("The maximum sum of the subarray is: %d\n", max);
    return 0;
}