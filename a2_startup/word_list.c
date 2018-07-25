/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/

#include "word_list.h"
#include "io.h"
#include "player.h"
/******************************************************************************
 * the word_list module simply keeps track of all the words in our
 * "dictionary". After loading from disk, the main purpose of this list will be
 * to check that a word exists in the dictionary. You will need to create the
 * functions for managing this list.
 *****************************************************************************/
/* Source code adapted from list.c
 * Source: https://github.com/muaddib1971/c_examp/blob/master/tutes/wk7/list.c
 * Author: Paul Miller
 * Date: 24th July 2018. */
BOOLEAN wordlist_init(struct word_list* wordlist) {
    struct word_node* word_node;
    memset(wordlist, 0, sizeof(struct word_list));
    wordlist->head =
        (struct word_node*)malloc(sizeof(word_node) * MAX_WORD_LEN);
    if (wordlist->head == NULL) {
        error_print("Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }
    /* If true we pass in the list to the size */
    wordlist->len = MAX_WORD_LEN;
    return EXIT_SUCCESS;
}

/* Source code adapted from list.c for personlist
 * Source:
 * https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-07/list.c
 * Author: Paul Miller
 * Date: 25th July 2018.*/
BOOLEAN wordlist_add(struct word_list* wordlist, char* word) {
    struct word_node *current, *prev = NULL;
    struct word_node* new;

    /* Check for valid pointers */
    assert(wordlist);
    assert(word);

    /* We use safemalloc and then initialise the next pointer and word char */
    new = safemalloc(sizeof(struct word_node));
    new->next = NULL;
    new->word = word;
    /* If we are at NULL, at the beginning of the list, we assign a new word
    node to the head of the list */
    if (wordlist->head == NULL) {
        wordlist->head = new;
        wordlist++->count;
        return EXIT_SUCCESS;
    }
    current = wordlist->head;
    /* Insertion at the beginning of the list */
    if (prev == NULL) {
        new->next = wordlist->head;
        wordlist->head = new;
    } else {
        /* Insertion at the end of the list */
        prev->next = new;
        new->next = current;
    }
    wordlist++->count;
    return EXIT_SUCCESS;
}

/* Wordlist function that frees the list. Good for clearing or
   cleaning out random statements */
void wordlist_free(struct word_list* wordlist) {
    struct word_node* current = wordlist->head;
    /* while the current list is not empty we assign the next node
       to the current one */
    while (current != NULL) {
        struct word_node* next;
        next = current;
        current = current->next;
        free(next->word);
        free(next);
    }
}
