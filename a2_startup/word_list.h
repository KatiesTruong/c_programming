/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared.h"

#ifndef WORD_LIST_H
#define WORD_LIST_H

#define DIRECTORYSIZE 10
/* the longest word supported by this program */
#define MAX_WORD_LEN 15

/**
 * linked node that points to the next node and holds the char pointer for
 * the word
 **/
struct word_node {
    char* word;
    struct word_node* next;
    struct player* data;
};

/**
 * list header structure. holds a pointer to the head node and the length
 * of the list, in case we need that.
 **/
struct word_list {
    struct word_node* head;
    int len;
    unsigned count;
    unsigned maxsize;
};

/* publicly callable functions from this module */
void wordlist_init(struct word_list*);
BOOLEAN wordlist_add(struct word_list*, struct player*);
void wordlist_free(struct word_list*);

#endif
