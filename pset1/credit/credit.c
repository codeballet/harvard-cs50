/*
 * Validate credit cards
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>


// Define prototypes
int get_digits(long num);
int get_first_two(long n);


int main(void)
{
    // Get card number
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    // Calculate checksum
    int odd = 0;
    int sum_odd = 0;
    int even = 0;
    int sum_even = 0;
    int checksum;
    long rest = num;
    while (rest > 0)
    {
        // Get odd position digit from end of number
        odd = rest % 10;
        rest /= 10;
        sum_odd += odd;

        // Get even position digit from end of number
        even = rest % 10;
        rest /= 10;
        // Multiply even numbers by 2
        even *= 2;
        // Sum numbers smaller than 10
        if (even < 10)
        {
            sum_even += even;
        }
        // Split up and then sum larger numbers
        // e.g. 12 as 1 + 2
        else
        {
            sum_even++;
            sum_even += even % 10;
        }
    }

    // Get the total checksum
    checksum = sum_odd + sum_even;

    // Get the results
    string result;
    int digits = get_digits(num);
    int first_two = get_first_two(num);

    if (checksum % 10 == 0)
    {
        if ((digits == 15) && (first_two == 34 || first_two == 37))
        {
            result = "AMEX";
        }
        else if ((digits == 16) && (first_two >= 51 && first_two <= 55))
        {
            result = "MASTERCARD";
        }
        else if ((digits == 16 || digits == 13) && (first_two / 10 == 4))
        {
            result = "VISA";
        }
        else
        {
            result = "INVALID";
        }
    }
    else
    {
        result = "INVALID";
    }

    printf("%s\n", result);
    return 0;
}


// Calculate number of digits
int get_digits(long num)
{
    return floor(log10(num) + 1);
}


// Get first two digits
int get_first_two(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    return n;
}