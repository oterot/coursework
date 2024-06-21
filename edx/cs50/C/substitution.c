#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int NUM = 26;

int main(int argc, string argv[])
{
    // must have only one command-line argument which is a 26 alpha-only string, comprising the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // get the length of the key, used multiple times below
    int n = strlen(argv[1]);

    if (n != NUM)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }


    int key_map[NUM]; // will map each letter of the alphabet to corresponding key character
    static int counts[NUM]; // used to check for duplicates
    char c; // will track current character in key string
    int k; // will contain the converted index value of the current key char

    // check key is all aphas and no duplicates
    // build key_map array to map alphabet characters to their encrypted values based on key string in argv[1]
    for (int i = 0; i < n; i++)
    {
        c = argv[1][i];

        // if any of the chars are not alpha exit with message
        if (!isalpha(c))
        {
            printf("Key must be 26 alpha characters.\n");
            return 1;
        }
        else // increment corresponding count and assign letter mapping
        {
            // convert the ascii key char int value (65-90) to (0-25) for 'A' to 'Z'
            k = (int)toupper(c) - 'A';
            // increment count to check for duplication
            counts[k]++;

            // exit with error is key has duplicates
            if (counts[k] > 1)
            {
                printf("Key must not contain duplicate characters.\n");
                return 1;
            }
            else
            {
                // i represent current letter of the alphabet (e.g. 0 is 'A' for first letter, etc.)
                // k represents the corresponding value in the key string that i gets converted to.
                key_map[i] = k;
            }
        }
    }

    // convert plaintext input to ciphertext
    string text = get_string("plaintext: ");
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        // current plaintext character
        c = text[i];

        // separate based on upper or not; and only apply transformation to alpha characters
        if (isalpha(c))
        {
            // convert ascii int values to 0-25 for indexing key_map
            c = isupper(text[i]) ? c - 'A' : c - 'a';
            k = isupper(text[i]) ? key_map[(int)c] + 'A' : key_map[(int)c] + 'a';
            // replace current plaintext char with corresponding ciphertext char
            text[i] = (char)k;
        }
    }

    // print out encrypted text
    printf("ciphertext: %s\n", text);

    return 0;

}