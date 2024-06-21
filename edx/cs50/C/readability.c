#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // take a string from the user to predict the grade level of using the Coleman-Liau index
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // we only count actual alpha characters
        if (isalpha(text[i]))
        {
            letters = letters + 1;
        }

        // we assume a space always indicates a separation of words
        if (text[i] == ' ')
        {
            words = words + 1;
        }

        // we assume that '.', '?', and '!' punctuate the end of a sentence
        if (text[i] == '.' | text[i] == '?' | text[i] == '!')
        {
            sentences = sentences + 1;
        }

    }

    // l is the average number of letters per 100 words
    float l = letters / (words / 100.0);

    // s is the average number of sentences per 100 words
    float s = sentences / (words / 100.0);

    float index = .0588 * l - .296 * s - 15.8;

    // if index is less than 1, assume it's pre-gradeschool
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // if greater than 16 is beyond typical college level
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    // print out the grade level calculated by the index
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}