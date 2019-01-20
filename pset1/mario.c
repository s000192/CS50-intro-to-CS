#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initialize n as integers
    int n;

    //prompt the user to input the height of bricks
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    //initialize i, j, k
    //i for the height
    //j for the space
    //k for the bricks #
    int i;
    int j;
    int k;

    //starting for loop counting the heights
    for (i = 0; i < n; i++)
    {
        //on the same line, print sufficient amount of space
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        //on the same line, print sufficient amount of bricks#
        for (k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        //going to the next line
        printf("\n");
    }
}