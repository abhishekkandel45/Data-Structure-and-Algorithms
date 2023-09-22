// Find duplicate elements in an array 

#include <stdio.h>
#include <stdlib.h>

void find_duplicate(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate element found: %d\n", arr[i]);
            }
        }
    }
} 



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
    find_duplicate(arr, size);
    return 0;

}