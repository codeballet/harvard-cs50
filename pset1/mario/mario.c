/*
 * Build a Mario pyramid
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user input for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // Build the pyramid row by row
    for (int i = 0; i < height; i++)
    {
        // Left-aligned pyramid spaces
        int spaces = height - i - 1;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        
        // Left-aligned pyramid hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        
        // Space between pyramids
        printf("  ");
        
        // Right-aligned pyramid
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        
        // Move to new row
        printf("\n");
    }
    return 0;
}