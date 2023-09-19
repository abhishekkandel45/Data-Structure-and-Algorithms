//Sum of interger in an array

#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
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
    int sum_of_array = sum(arr, size);
    printf("The sum of the array is: %d\n", sum_of_array);
    return 0;
}