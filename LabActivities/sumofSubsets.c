// Write a program to implement sum of subsets problem using backtracking.

#include<stdio.h>
#include<stdlib.h>

int x[10],w[10],d,count=0;

void sumOfSubsets(int s,int k,int r)
{
    int i;
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("\nSubset %d\n",++count);
        for(i=0;i<=k;i++)
            if(x[i]==1)
                printf("%d\t",w[i]);
    }
    else if(s+w[k]+w[k+1]<=d)
        sumOfSubsets(s+w[k],k+1,r-w[k]);
    if((s+r-w[k]>=d)&&(s+w[k+1]<=d))
    {
        x[k]=0;
        sumOfSubsets(s,k+1,r-w[k]);
    }
}

void main()
{
    int i,n,sum=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order: ");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    printf("Enter the required sum: ");
    scanf("%d",&d);
    for(i=0;i<n;i++)
        sum+=w[i];
    if(sum<d)
        printf("No solution exists");
    else
        sumOfSubsets(0,0,sum);
}
