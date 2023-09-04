/* 
Date: 9/4/2023
Given two arrays weight and Profit of n items we need to  put these items in 
kanpsack of capacity W to get the maximum total profit in the knapsack.
Fractional Knapsack Problem: We can break items for maximizing the total value of knapsack.
*/
#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int value;
    int weight;
};


// Function to get maximum value
int compare(const void *a, const void *b)
{
    double r1 = (double)(((struct Item *)a)->value / (double)((struct Item *)a)->weight); 
    double r2 = (double)(((struct Item *)b)->value / (double)((struct Item *)b)->weight);
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    else
        return 0;
}

// Main function
int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the Weight of knapsack: ");
    scanf("%d", &W);
    struct Item arr[n];
    printf("Enter the value and weight of items: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    qsort(arr, n, sizeof(arr[0]), compare);      // Sort the items by value/weight ratio

//Printitng the items sorted by value/weight ratio with their value and weight
//Tabular format
    printf("Items sorted by value/weight ratio: \n");
    printf("Item\tValue\tWeight\tValue/Weight\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%lf\n", i + 1, arr[i].value, arr[i].weight, (double)arr[i].value /  (double)arr[i].weight);
    }

    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }


    }
    printf("Maximum value we can obtain = %lf\n", finalvalue);
    return 0;
}