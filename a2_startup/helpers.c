/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "helpers.h"
/******************************************************************************
 * the helpers module is a great place to store functions that don't logically
 * "live" in another module.
 *****************************************************************************/

/* Source code adapted from fsupport.c
 * Author: Paul Miller
 * Source:
 * https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-05/fsupport.c
 * Date: 19th July 2018.*/
/* Function that opens files and outputs error when it fails */

FILE* file_open(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        /* return file when succeeds to open*/
        fprintf(stderr, "Failed to open %s file: %s\n", file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return file;
}

/* Function that opens and write files */

FILE* file_write(char* file_name) {
    FILE* file;
    if ((file = fopen(file_name, "w")) == NULL) {
        fprintf(stderr, "Failed to open %s file: %s\n", file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return file;
}

void swap_words(int* letter1, int* letter2) {
    int temp = *letter1;
    *letter1 = *letter2;
    *letter2 = temp;
}

void bubble_sort(struct word_node* node, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; size - 1 - i; j++) {
            struct word_node temp;
            if (node[j].word_len > node[j + 1].word_len) {
                temp = node[j + 1];
                node[j + 1] = node[j];
                node[j] = temp;
                normal_print("%s\n", temp);
            }
        }
    }
}
/* Source codes adapted from StackOverflow and s_dl_malloc.c
 * Source:
 * stackoverflow.com/questions/27594992/uninitialized-value-was-created-by-a-heap-allocation
 * Source: 26th July 2018.*/
/* Loads data in from disk */
int load(struct word_list* wordlist, FILE* fp_read) {
    int len, i;
    char* buffer;
    struct word_node* node;
    buffer = malloc(sizeof(node));
    while (fgets(buffer, WORD_LEN + EXTRACHARS, fp_read) != NULL) {
        node = malloc(sizeof(node));
        len = strlen(buffer);
        node->word = malloc(sizeof(char) * len);
        /* loop the word list in the file */
        /* NOTE: create a bubble sort algorithm*/
        for (i = 0; i < len - 1; i++) {
            /*qsort(node->word, sizeof(node->word), sizeof(char*),
                  order_wordlist);*/
            node->word[i] = buffer[i];
            node->word[len - 1] = '\0';
            node->next = NULL;
            /* Debugging */
            /*normal_print("%s\n", node->word);*/
        }
        /*bubble_sort(node, len);*/
    }
    free(node->word);
    return EXIT_SUCCESS;
    /*struct word_node* word_node;
    size_t size_words = 0;
    char buffer[NUM_LETTERS + EXTRA_CHARS];
    malloc(sizeof(word_node) * 100);
    while(fgets(buffer, NUM_LETTERS + EXTRA_CHARS, fp_read) != NULL) {

    }*/
}
