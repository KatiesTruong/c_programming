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
void wordlist_init(struct word_list* wordlist) {
    /*struct word_node* word_node;*/
    assert(wordlist);
    wordlist->head = NULL;
    wordlist->count = 0;
    memset(wordlist, 0, sizeof(struct word_list));
    /* wordlist->head =
         (struct word_node*)malloc(sizeof(word_node) * MAX_WORD_LEN);
     if (wordlist->head == NULL) {
         error_print("Failed to allocate memory.\n");
         return EXIT_FAILURE;
     }
     wordlist->len = MAX_WORD_LEN;
     return EXIT_SUCCESS;*/
}

/* Source code adapted from list.c for personlist
 * Source:
 * https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-07/list.c
 * Author: Paul Miller
 * Date: 25th July 2018.*/
BOOLEAN wordlist_add(struct word_list* wordlist, struct player* data) {
    struct word_node *current, *prev = NULL;
    struct word_node* new;

    /* Check for valid pointers */
    assert(wordlist);
    assert(data);

    /* We use safemalloc and then initialise the next pointer and word char */
    new = safemalloc(sizeof(struct word_node));
    new->next = NULL;
    new->data = data;
    /* If we are at NULL, at the beginning of the list, we assign a new word
    node to the head of the list */
    if (wordlist->head == NULL) {
        wordlist->head = new;
        wordlist->count += 1;
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
    wordlist->count += 1;
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
        free(next->data);
        free(next);
    }
}

void print_wordlist(struct word_list* wordlist) {
    struct word_node* current;
    assert(wordlist);
    /* We start at the beginning of the list */
    current = wordlist->head;
    /* while we have content in the list*/
    while (current) {
        /* struct tile* data = current->data;*/
        normal_print("%s\t", wordlist->head);
        current = current->next;
    }
}

/* Source code adapted from safemalloc.c file
 * Source:
 * https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-07/safemalloc.c
 * Author: Paul Miller
 * Date: 25th July 2018.*/
/* Functions for safe memory allocation */
void* safe_malloc(size_t size, unsigned long line_num) {
    void* result;
    result = malloc(size);
    if (!result) {
        fprintf(stderr, "Failed to allocate %s memory: %s\n", result,
                strerror(errno));
        fprintf(stderr, "On line: %ld\n", line_num);
        exit(EXIT_FAILURE);
    }
    return result;
}
