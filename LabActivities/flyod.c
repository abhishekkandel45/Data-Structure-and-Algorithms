/* Folyed Warshall Incrimental Algorithm for finding the shortest path between all pairs of nodes in a graph
    Algorithm:


        1. Let D be a n x n array of distances initialized to the weight of the edges
        2. for k = 1 to n
        3.     for i = 1 to n
        4.         for j = 1 to n
        5.             D[i][j] = min(D[i][j], D[i][k] + D[k][j])
        6. return D


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;    // if a < b return a else return b  for finding the minimum of two numbers
}

int main() {
    int n, i, j, k;
    int D[MAX][MAX];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &D[i][j]);
        }
    }
    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    printf("The distance matrix is: \n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
