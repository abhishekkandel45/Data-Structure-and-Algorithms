//Program to calculate the sum of digit od number using recursion

#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int n);

int main (){
    int n;
    printf("Enter a number: ");
    scanf ("%d", &n);
    printf("The sum of digits of %d is %d\n", n, sumOfDigits(n));
    return 0;
}

int sumOfDigits(int n){
    if (n == 0){
        return 0;
    }
    else{
        return (n%10 + sumOfDigits(n/10));
    }
}
