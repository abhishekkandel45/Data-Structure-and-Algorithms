#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare the array A with size n
    int A[n];

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Insertion Sort Algorithm
    for (j = 2; j < n; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }

    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
