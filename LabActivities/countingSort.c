// Date: 7 Aug 2023

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n)
{
    int i, j, max = 0;
    //Finding the maximum element in the array
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

//Initializing the count array of size max + 1 with 0
    int count[max + 1];
    for (i = 0; i < max + 1; i++)
        count[i] = 0;

//Storing the count of each element at their respective index in count array
    for (i = 0; i < n; i++)
        count[arr[i]]++;

//Storing the cumulative count of each array
    for (i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

//Finding the index of each element of the original array in count array and placing the elements in output array
    int output[n];
    for (i = n - 1; i >= 0; i--)            //Iterating from n - 1 to 0
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;                //Decreasing the count by 1
    }

//After placing each element at its correct position, decrease its count by 1
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

//Driver Code
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    countingSort(arr, n);
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
