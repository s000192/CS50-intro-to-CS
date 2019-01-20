// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

//define the linked list /
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//create a hash table
node *hashtable[25];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = hashtable[(word[0] - 97) % 26];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word) == 0)
        {
            return true;
        }

        else
        {
            cursor = cursor->next;
        }
    }
    return true;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open dictionaries
    FILE *file;
    file = fopen(dictionary, "r");

    char *word = NULL;

    //scan dictionary word by word
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        //copy word into node
        strcpy(new_node->word, word);

        //insert the node to a linked list
        new_node->next = hashtable[(word[0] - 97) % 26];
        hashtable[(word[0] - 97) % 26] = new_node;
    }
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int i=0;
	while(first!=NULL)
	{
		first=first->next;
		i++;
	}
    return i;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //for every bucket
    for (int n = 0; n < 26; n++)
    {
        node *cursor = hashtable[n];
        //free them one by one on the linked list of one bucket
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
