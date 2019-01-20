#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //prompt user to type in the change owed
    float c;
    do
    {
        c = get_float("Change owed: ");
    }
    while (c <= 0);

    //convert the value into cents
    c = c * 100;

    //rounding c to integers
    c = round(c);

    //find out how many coins
    int n = 0;

    //deducting 25 cents from the change owed "c" until it's smaller than 25 cents
    while (c >= 25)
    {
        c = c - 25;
        n = n + 1;
    }
    //deducting 10 cents from the change owed "c" until it's smaller than 10 cents
    while (c >= 10)
    {
        c = c - 10;
        n = n + 1;
    }

    //deducting 5 cents from the change owed "c" until it's smaller than 5 cents
    while (c >= 5)
    {
        c = c - 5;
        n = n + 1;
    }

    //deducting 1 cents from the change owed "c" until it's smaller than 1 cents
    while (c >= 1)
    {
        c = c - 1;
        n = n + 1;
    }

    //print out the number coins needed
    printf("%i\n", n);
}