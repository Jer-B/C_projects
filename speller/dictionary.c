/*
    CS-50 pset-5: Speller.
    description: Check a dictionnary, using Hash table
    @file credit.c
    @author Jeremy B.
    @version 1.0 7 Nov 2020
*/

// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h> //file fopen / fscanf / fread
#include <stdlib.h> //malloc / free
#include <string.h> //strcpy
#include <ctype.h> //tolower

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 200000;

// Hash table
node *table[N];

//Word count for size function
unsigned int word_count;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char word_check[LENGTH + 1];
    int word_len = strlen(word);

    if (word_len > LENGTH)
    {
        return false;
    }

    //iterate through word to transform all letters in lower case, and word check = lower word
    for (int i = 0; word[i] != '\0'; i++)
    {
        word_check[i] = (char)tolower((unsigned char)word[i]);
    }

    word_check[word_len] = '\0';

    // get the index by using the hash function
    int index = hash(word_check);

    // check if the word is in the hash table
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(tmp->word, word_check) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // credits : https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn?utm_source=share&utm_medium=web2x&context=3
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash << 2) ^ word[i];
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
//check input ./speller texts/lalaland.txt
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];

    //word count incrementation for size function
    word_count = 0;
    // open dictionary file
    FILE *input_file = fopen(dictionary, "r");
    if (input_file == NULL)
    {
        return false;
    }

    //load while file word != EOF
    while (fscanf(input_file, "%s", word) != EOF)
    {
        //allocate new node
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            fclose(input_file);
            return false;
        }

        //copy word to new node and set new node next to null
        strcpy(new_node->word, word);

        //need to do hash word index
        int index = hash(word);

        //insert new node into hash table + becoming new head of the list
        new_node->next = table[index];
        table[index] = new_node;

        //word count incrementation for size function
        word_count++;
    }

    // close the opened file
    fclose(input_file);
    //fclose(input_file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int *count = &word_count;
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    //unload memory through hash table size
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *next = table[i]->next;
            free(table[i]);
            table[i] = next;
        }
    }

    return true;
}
