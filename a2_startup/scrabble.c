/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "scrabble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define READER_DICT 1
#define READER_TILES 2

/******************************************************************************
 * the scrabble module contains the main function and any helper functions to
 * kick start the program and clean up at the end.
 *****************************************************************************/
int main(int argc, char* argv[]) {
    struct word_list wordlist;
    unsigned seed;
    FILE *fp_read_dict, *fp_read_tile;
    int result_dict, result_tile;
    /* Source code adapted from reader.c
     * Author: Paul Miller
     * Source:
     * Date: 19th July 2018. */
    /* Initialise the wordlist */
    wordlist_init(&wordlist);
    /* memset(wordlist, 0, sizeof(struct word_list) * DIRECTORYSIZE);*/
    /* validate command line arguments */
    /* We place != since we process 3 files*/
    if (argc != 3) {
        error_print("Invalid arguments.\n");
        return EXIT_FAILURE;
    } else if (strlen(argv[1]) <= 5) {
        error_print("Dictionary words are not within limt.\n");
        return EXIT_FAILURE;
    }
    /* opens the files for dictionary and tiles text */
    fp_read_dict = file_open(argv[READER_DICT]);
    fp_read_tile = file_open(argv[READER_TILES]);
    /* when loading data we handle the errors, where -1 is returned a true value
     * for opening the file */
    fclose(fp_read_dict);
    fclose(fp_read_tile);
    if (result_dict < -1 && result_tile < -1) {
        error_print("Failed to load data.\n");
        return EXIT_FAILURE;
    }

    /* display a welcome message */
    normal_print("Please wait while we load the dictionary...\n");
    /* extract the seed */
    srand(seed);
    /* if the seed has been provided by the user, extract the
     * number from the string provided - please note that I am not
     * using strtoint as we need a long int */
    /* if the seed is not provided, generate the seed for the
     * current second */

    /* start the random number generator */

    /* output the seed being used */
    /* load the dictionary file */
    result_dict = load(&wordlist, fp_read_dict);
    result_tile = load(&wordlist, fp_read_tile);
    /* wordlist_add(&wordlist, );*/
    /* play the game :) */
    /* free memory */
    wordlist_free(&wordlist);
    return EXIT_SUCCESS;
}
