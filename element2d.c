//Program 2 first lab Date: 2023/07/17

//program to search an elememt in 2d ARRAY

#include <stdio.h>
#include <stdlib.h>

int main()
{
     //Variable initilization  2d Arrrays
     int i[3][3], j, k, l, m, n, *ptr;
     printf ("Enter the elements of the array:");
        for (j=0; j<3; j++)
        {
            for (k=0; k<3; k++)
            {
                scanf ("%d", &i[j][k]);
            }
        }

    printf ("Enter the element to be searched:");
    scanf ("%d", &l);
ptr= &i[0][0];
    for (m=0; m<3; m++)
    {
        for (n=0; n<3; n++)
        {
            if (l== *(ptr+m*3+n))
            {
                printf ("The element is found at %d row and %d column \n", m+1, n+1);
                exit (0);
            }
        }
    }
    printf ("The element is not found \n");
    return 0;
}