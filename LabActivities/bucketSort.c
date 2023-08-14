/* 
Bucket Sort Algorithm
Date: Aug 14, 2023
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 15 

// Function Prototypes 
void bucketSort(int array[], int n);    // Bucket Sort Algorithm
void printArray(int array[], int n);    // Print Array

//Function Definitions for Bucket Sort Algorithm
void bucketSort(int array[], int n) {
    int i, j, k, buckets[MAX];             
    for (i = 0; i < MAX; ++i) {             // Initialize Buckets
        buckets[i] = 0;
    }
    for (i = 0; i < n; ++i) {               // Count the number of elements in each bucket
        ++buckets[array[i]];                
    }

    for (i = 0, j = 0; j < MAX; ++j) {      // Sort the elements of each bucket using insertion sort
        for (k = buckets[j]; k > 0; --k) {
            array[i++] = j;
        }
    }
}

// Function Definitions for Print Array
void printArray(int array[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Main Function
int main() {
    int array[MAX], i, num;
    printf("Enter the size of array : ");
    scanf("%d", &num);
    printf("Enter the %d elements to be sorted:\n",num);
    for (i = 0; i < num; ++i) {
        scanf("%d", &array[i]);
    }
    printf("\nThe array of elements before sorting : \n");
    printArray(array, num);
    printf("\nThe array of elements after sorting : \n");
    bucketSort(array, num);
    printArray(array, num);
    return 0;
}

        