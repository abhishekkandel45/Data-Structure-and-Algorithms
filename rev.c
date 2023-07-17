//Program to reverse a number using pointer 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, rev=0, p, *ptr;
    printf("Enter the number:");
    scanf ("%d", &n);
    ptr= &n;
    while (n>0)
    {
        p= n%10;
        rev= rev*10+p;
        n= n/10;
    
    }
    printf("The reverse of the number is %d \n", rev);
    return 0;
}


