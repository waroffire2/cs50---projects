#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
/*
Formula:
index = 0.0588 * L - 0.296 * S - 15.8
L = # of letters / words
S = # sentences / words
*/

int count_letters(string text);
int count_words(string text);
int count_sen(string text);

int main(void)
{
    int letters, sentences, words, grade;
    float L, S, X;

    string text = get_string("text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sen(text);

    L = ((float) letters / words) * 100;
    S = ((float) sentences / words) * 100;

    X = (0.0588 * L) - (0.296 * S) - 15.8;
    grade = (int) (X + 0.5);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int sum = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 32)
        {
            sum++;
        }
    }
    return sum + 1;
}

int count_sen(string text)
{
    int sum = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sum++;
        }
    }
    return sum;
}
