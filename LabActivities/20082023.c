/*
We are given an items where each item has some wight and profit associated with it. We are also given a bag with a capacity (W) weight in it.
The Target is to put the items into the bag such that the sum of profits associated with them is the maximum possible.
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;     // if a > b then return a else return b
}

int knapsack(int W, int wt[], int val[], int n)   // W = capacity of the bag, wt = weight of the items, val = profit of the items, n = number of items
{
    // Base Case
    if (n == 0 || W == 0)    //Or Operation
        return 0;

    // If weight of the nth item is more than Knapsack capacity W, then this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
}

int main()
{
    //User Input
    int n, W;
    printf("Enter the number of items: ");
    scanf ("%d", &n);
    printf("Enter the capacity of the bag: ");
    scanf ("%d", &W);

    int val[n], wt[n];
    printf("Enter the value and weight of the items: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf ("%d %d", &val[i], &wt[i]);
    }

    printf("The maximum profit is: %d", knapsack(W, wt, val, n));
    return 0;
}