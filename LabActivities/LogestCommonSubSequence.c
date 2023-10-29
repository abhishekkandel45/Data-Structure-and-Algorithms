//Longest Common Subsequence using Dynamic Programming

#include <stdio.h>
#include <string.h>

int lcs (char *X, char *Y, int m, int n)
{
    int L[m+1][n+1];
    int i, j;
    
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i==0 || j==0)   // Base Case (when one of the string is empty)
                L[i][j] = 0;  //
            else if (X[i-1] == Y[j-1])  // If last characters are same, add 1 to the result
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];  // If last characters are not same, consider the maximum of two
        }
    }
    
    return L[m][n];
}

// Driver program to test above function
int main()
{
    printf("Please enter the first string: ");
    char X[100];
    scanf("%s", X);
    printf("Please enter the second string: ");
    char Y[100];
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n));

    return 0;
}