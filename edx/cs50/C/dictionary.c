// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Track size of dictionary
int numWords = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char temp[LENGTH + 1];
    strcpy(temp, word);
    for (int i = 0, n = strlen(temp); i < n; i++)
    {
        //if it's uppercase convert to lower
        if (isalpha(temp[i]))
        {
            temp[i] |= 'a' - 'A';
        }
    }

    //go to appropriate place in hashtable look for a match
    int index = hash(temp);
    for (node *p = table[index]; p != NULL; p = p->next)
    {
        if (strcmp(p->word, temp) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 65;
}

// creates a new node and returns its address
node *create_node(void)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    //initialize node values
    new_node->next = NULL;

    return new_node;
}

// Inserts a node into the hashtable
void append(node *newNode, const int index)
{
    //if bucket is empty have bucket point to newNode
    if (table[index] == NULL)
    {
        table[index] = newNode;
        return;
    }

    //traverse the hashtable's linked list
    for (newNode->next = table[index]; newNode->next != NULL;
         newNode->next = newNode->next->next)
    {
        //if at the end of the link list, insert node
        if (newNode->next->next == NULL)
        {
            newNode->next->next = newNode;
            newNode->next = NULL;
            return;
        }
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    char word[LENGTH + 1];
    if (dict != NULL)
    {
        while (fscanf(dict, "%s", word) != EOF)
        {
            // create a new node and place into hashtable
            node *newNode = create_node();
            int index = hash(word);
            strcpy(newNode->word, word);
            append(newNode, index);
            numWords++;
        }
        fclose(dict);
        return true;
    }
    fclose(dict);
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return numWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            //free all the nodes in one bucket without orphaning children
            node *cursor = table[i]->next;
            free(table[i]);
            table[i] = cursor;
        }
    }
    return true;
}