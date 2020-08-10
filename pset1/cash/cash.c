/*
 * Calculate number of coins for change
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Get user input for changed owed
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0.001);

    // Convert change owed to cents
    int cents = round(change * 100);

    // Create variables to keep track of
    int coins;
    int quarters;
    int dimes;
    int nickels;
    int remaining = cents;

    // Calculate quarter coins
    quarters = floor(remaining / 25);
    remaining -= quarters * 25;

    // Calculate dime coins
    dimes = floor(remaining / 10);
    remaining -= dimes * 10;

    // Calculate nickel coins
    nickels = floor(remaining / 5);
    remaining -= nickels * 5;

    // Calculate total number of coins
    coins = quarters + dimes + nickels + remaining;

    printf("Coins: %i\n", coins);
}