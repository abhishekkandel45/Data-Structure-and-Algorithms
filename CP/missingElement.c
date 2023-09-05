/*
Given an unsorted array, find the mission element in the array  
Input: [1,2,3,5,5]
Output: 4
Input: [2,3,5,2,4]
Output: 1

*/

#include <stdio.h>
#include <stdlib.h>

int  main()
{
printf("Enter the size of the array\n");
int n;
scanf("%d",&n);
int arr[n];
printf("Enter the elements of the array\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
 //Auxillary array
int aux[n+1];
for(int i=0;i<n+1;i++)
{
aux[i]=0;
}
for(int i=0;i<n;i++)
{
aux[arr[i]]++;
}
for(int i=1;i<n+1;i++)
{
if(aux[i]==0)
{
printf("The missing element is %d\n",i);
break;
}
}
return 0;
}


