// Program to check wherather the number 


#include <stdio.h>
#include <stdlib.h>

void isPalindrome(int n);
//Function Defination

void isPalindrome(int n){
    int rev = 0;
    int temp = n;
    while (temp != 0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    if (n==rev)
    {
        return "Palindrome"

        