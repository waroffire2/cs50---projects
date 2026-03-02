#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string text);

int main(int argc, string argv[])
{
    // Check all conditions
    // 1. If command line has 2 arguments only
    // 2. Is the key valid (26 unique characters)
    if (argc != 2 || !(is_valid_key(argv[1])))
    {
        printf("Usage: ./substitution key\n");
        printf("(Key must contain 26 unique characters.)\n");
        return 1;
    }

    // Prompt user for text
    string plaintext = get_string("plaintext:  ");

    // Allocate memore for cipher text
    string ciphertext = malloc(strlen(plaintext) + 1);
    if (ciphertext == NULL)
    {
        return 1;
    }

    // Allocate memory for key then copy the argv[1] to key
    string key = malloc(strlen(argv[1]) + 1);
    if (key == NULL)
    {
        free(ciphertext);
        return 1;
    }
    strcpy(key, argv[1]);

    int index = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // If plaintext[i] is not a letter but space, ! or anything else
        if (!(isalpha(plaintext[i])))
        {
            ciphertext[i] = plaintext[i];
        }
        else if (isupper(plaintext[i]))
        {
            index = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[index]);
        }
        else
        {
            index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index]);
        }
    }
    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);
    free(key);
}

// Check if the code is only alphabetical letters
// Each letter has to be chosen once
bool is_valid_key(string text)
{
    if (strlen(text) != 26)
    {
        return false;
    }

    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (!(isalpha(text[i])))
        {
            return false;
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = row + 1; col < n; col++)
        {
            if (tolower(text[col]) == tolower(text[row]))
            {
                return false;
            }
        }
    }
    return true;
}
