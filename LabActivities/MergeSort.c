//  Merge Sort
//Date :31/07/2023

#include  <stdio.h>
#include  <stdlib.h>

#define MAX 100

void merge(int A[], int p,int q, int r);  //  This array is used to merge the array
void mergeSort(int A[], int p, int r);  //  This array is used to sort the array
void printArray(int A[], int size);   //  This array is used to print the array


// Function call to print the array
void merge(int A[], int p,int q, int r) 
/*
Here p is the starting index of the array
q is the middle index of the array
r is the last index of the array
A is the array to be sorted
*/  
{
    int n1 = q - p + 1;     //Array to store the left side of the Aray
    int n2 = r - q;
    int i = 0; 
    int j = 0;
    int k = 0;

    int L[n1];      //  This array is used to store the left side of the array
    int R[n2];      //This array is used to store the rigtht side of the Array

    for (i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
} 

// Function call to sort the array
void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        merge(A, p, q, r);
    }
}

// Function call to print the array
void printArray(int A[], int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}



//Driver code
int main()
{
    int A[MAX] = { 0 };
    int i = 0;
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");

    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("The array before sorting: ");
    printArray(A, size);

    mergeSort(A, 0, size - 1);

    printf("The array after sorting: ");
    printArray(A, size);

    return 0;
}