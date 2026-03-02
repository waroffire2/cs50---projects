#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string text);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2 || !(only_digits(argv[1])))
    {
        printf("Usage ./ceaser key\n");
        return 1;
    }
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
}

bool only_digits(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!(isdigit(text[i])))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    if ((c >= 65 && c <= 90))
    {
        return (c - 'A' + key) % 26 + 'A';
    }
    else if ((c >= 97 && c <= 122))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    return c;
}
