// Date:8/21/2023
// Radix Sort Algorithm

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
int findMax(int arr[], int n);
void radixSort(int arr[], int n);
void printArray(int arr[], int n);

void findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
}

void radixSort(int arr[], int n)
//without using Dyanmic Memory Allocation
{
    int i, j, m, p = 1, index, temp, count = 0;
    //find the maximum number in the array
    m = findMax(arr, n);
    //find the number of digits in the maximum number
    while (m > 0)
    {
        count++;
        m = m / 10;
    }
    
    // making  all the Number to have same number of digits
    for (i = 0; i < count; i++)
    {
        int bucket[10][10] = {0};              // This bucket is used for storing the elements
        int bucket_count[10] = {0};            // This bucket_count is used for storing the count of elements in each bucket
        for (j = 0; j < n; j++)
        {
            index = (arr[j] / p) % 10;                     //finding the index of the bucket
            bucket[index][bucket_count[index]] = arr[j];  //inserting the element into the bucket
            bucket_count[index] += 1;                     //incrementing the bucket count
        }
        //sorting the elements according to the digits
        index = 0;
        for (j = 0; j < 10; j++)
        {
            for (int k = 0; k < bucket_count[j]; k++)
            {
                arr[index] = bucket[j][k];
                index++;
            }
        }
        p = p * 10;
    }
}





void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}






//Driver Code
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("The array before sorting is: ");
    printArray(arr, n);
    radixSort(arr, n);
    printf("The array after sorting is: ");
    printArray(arr, n);
    return 0;
}