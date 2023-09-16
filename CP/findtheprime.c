// Program to find the Nearest Prime number to any number for examplple if uder inputs 5 it shoukld result 3 and 7

#include  <stdio.h>

int main(void)
{
    int num, i, j, flag;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num <= 1)
    {
        printf("Nearest prime number is 2");
    }
    else
    {
        for (i = num - 1; i > 1; i--)
        {
            flag = 0;
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("Nearest prime number is %d", i);
                break;
            }
        }
        for (i = num + 1;; i++)
        {
            flag = 0;
            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf(" and %d", i);
                break;
            }
        }
    }
    return 0;
}

