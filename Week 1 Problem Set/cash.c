#include <cs50.h>
#include <stdio.h>

/*
quarter - 25
dime - 10
nickel - 5
penny - 1
*/

int main(void)
{

    int changeOwed, coinsToGive = 0;
    const int QUARTER = 25, DIME = 10, NICKEL = 5, PENNY = 1;

    // Prompt user to put in a correct change owed input
    do
    {
        changeOwed = get_int("Change owed: ");
    }
    while (changeOwed < 0);

    if (changeOwed == 0) // Case if changeOwed == 0, so we don't have to loop
    {
        printf("0\n");
    }
    while (changeOwed >=25) // If changeOwed is >= 25, then keep decreasing by 25 and increment cointToGive by one
    {
        changeOwed -= QUARTER;
        coinsToGive++;
    }
    while (changeOwed >= 10) // Same for Dimes
    {
        changeOwed -= DIME;
        coinsToGive++;
    }
    while (changeOwed >= 5) // Same for Nickels
    {
        changeOwed -= 5;
        coinsToGive++;
    }
    while (changeOwed >= 1) // Same for pennies
    {
        changeOwed -= 1;
        coinsToGive++;
    }

    printf("%i\n", coinsToGive);
}
