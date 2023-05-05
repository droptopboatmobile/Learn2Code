#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //ask user for number between 1 and 8
    do
    {
        n = get_int("Please enter a number between 1 and 8: ");
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

        //print middle spaces
        printf("  ");

        //print right side
        for (int q = 0; q < i + 1; q++)
        {
            printf("#");
        }
        printf("\n");
    }
}