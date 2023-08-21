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

    //create a 2D array of size 10 * n (n is the number of elements in the array) to store the elements in static memory
    int np[10][10];
    int np_count[10];

    //initialise the 2D array with 0's
    for (i = 0; i < 10; i++)
    {
        np_count[i] = 0;
        for (j = 0; j < 10; j++)
            np[i][j] = 0;
    }

    //loop through the number of digits in the maximum number
    for (i = 0; i < count; i++)
    {
        //loop through the number of elements in the array
        for (j = 0; j < n; j++)
        {
            //find the index of the element to be stored in the 2D array
            index = (arr[j] / p) % 10;
            //store the element in the 2D array at the found index and increment the count at that index
            np[index][np_count[index]] = arr[j];
            np_count[index] += 1;
        }
        //loop through the 2D array
      
        //increment the power of 10
        p = p * 10;
        //reset the count of elements at each index to 0
        for (j = 0; j < 10; j++)
            np_count[j] = 0;
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