/*
Problem statement : Aman, who is working at a software company forgot the password of his Linkedin id.But he knows the ASCII values of his password in reverse order. Help aman to find the password.
To decode the password, first reverse the string of digits, then successively pick valid values from the string and convert them to their ASCII equivalents. Some of the values will have two digits, and others three. Use the ranges of valid values when decoding the string of digits.

Some of the ASCII values are given with their characters:

 The ASCII value of A to Z is 65 to 90.
 The ASCII value of a to z is 97 to 122.
 The ASCII value of space characters is 32.
Note: The password only has alphabets and blank spaces.

Given a string , decode the password by following the steps mentioned above.

Constraints:
1<= |s| <=10^5
s[i] is an ascii character in the range [A-Za-z] or a space character
Sample Input:
796115110113721110141108
Sample Output:
PrepInsta

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str[100000];
    scanf("%s",str);
    int len=strlen(str);
    int i=0;
    int j=len-1;
    while(i<j)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
    int k=0;
    while(k<len)
    {
        if(str[k]=='1')
        {
            int num=(str[k]-'0')*100+(str[k+1]-'0')*10+(str[k+2]-'0');
            if(num>=65 && num<=90)
            {
                printf("%c",num);
            }
            else if(num>=97 && num<=122)
            {
                printf("%c",num);
            }
            else if(num==32)
            {
                printf("%c",num);
            }
            k=k+3;
        }
        else
        {
            int num=(str[k]-'0')*10+(str[k+1]-'0');
            if(num>=65 && num<=90)
            {
                printf("%c",num);
            }
            else if(num>=97 && num<=122)
            {
                printf("%c",num);
            }
            else if(num==32)
            {
                printf("%c",num);
            }
            k=k+2;
        }
    }
    return 0;
}





