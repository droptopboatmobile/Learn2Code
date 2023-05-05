#include <stdio.h>

int main(void)
{
    int n;

    //Ask for user number input, repeat if < 1 or > 8
    do
    {
        printf("Please enter a number between 1 and 8: ");
        scanf("%d", &n);
    }
    while (n < 1 || n > 8);

    //for each row
    for (int i = 0; i < n; i++)
    {
        //first for each column print n - i " " characters
        for (int z = 1; z < n - i; z++)
        {
            printf(" ");
        }

        //then for each column print i "#" characters
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}