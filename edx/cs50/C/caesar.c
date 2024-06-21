#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid number of parameters.  Please include one parameter, an integer key.\n");
        return 1;
    }
    
    int key = atoi(argv[1]) % 26;
    
    printf("plaintext: ");
    string text = get_string();
 
    for (int i = 0, n = strlen(text); i < n; i++)
    {
       if (text[i] >= 'a' && text [i] <= 'z')
       {
           if (text[i] + key > 'z')
           {
               text[i] += key - 26;
           }
           else
           {
               text[i] = text[i] + key;
           }
       }
       if (text[i] >= 'A' && text [i] <= 'Z')
       {
           if (text[i] + key > 'Z')
           {
               text[i] += key - 26;
           }
           else
           {
               text[i] = text[i] + key;
           }
       }
       
      
    }
 
    printf("ciphertext: %s\n", text);

    return 0;
  
}