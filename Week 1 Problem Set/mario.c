#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0; // h represents height
    while (h <= 0 || h >= 9)
    {
        h = get_int("What is the size? ");
    }

    for (int row = 0; row < h; row++)
    {
        for (int space = 0; space < h - row - 1; space++) // relationship for each space is the height - row - 1
        {
            printf(" ");
        }

        for (int col = 0; col <= row; col++) // Prints out the hashes in the pyramid
        {
            printf("#");
        }

        printf("  "); // For spaces in the middle, no pattern here so it is easy to see

        for (int col = 0; col <= row; col++) // This covers the left lined pyramid
        {
            printf("#");
        }

        printf("\n");
    }
}
