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
#define FILE_SIZE 10

/******************************************************************************
 * the scrabble module contains the main function and any helper functions to
 * kick start the program and clean up at the end.
 *****************************************************************************/
int main(int argc, char* argv[]) {
    struct word_list wordlist;
    struct tile_list tilelist;
    struct player* players;
    unsigned seed;
    FILE *fp_read_dict, *fp_read_tile;
    int result_dict = 0, result_tile = 0;
    long int randomise;
    char name[NAMELEN + EXTRACHARS];
    char* rand_str = argv[3];

    BOOLEAN quit = FALSE;
    /* Source code adapted from reader.c
     * Author: Paul Miller
     * Source:
     * Date: 19th July 2018. */
    /* Initialise the wordlist */
    wordlist_init(&wordlist);
    /* memset(wordlist, 0, sizeof(struct word_list) * DIRECTORYSIZE);*/
    /* validate command line arguments */
    /* We place != since we process 3 files*/
    /* if (argc != 3) {
        error_print("Invalid arguments.\n");
        return EXIT_FAILURE;
    } else if (strlen(argv[1]) >= MAX_WORD_LEN) {
        error_print("Dictionary words are not within limt.\n");
        return EXIT_FAILURE;
    }*/
    /* opens the files for dictionary and tiles text */
    fp_read_dict = file_open("words.len5"); /* argv[READER_DICT] = argv[1] */
    fp_read_tile = file_open("tiles.txt");  /* argv[READER_TILES] = argv[2] */
    fseek(fp_read_dict, FILE_SIZE, SEEK_SET);
    fseek(fp_read_tile, FILE_SIZE, SEEK_SET);
    /* when loading data we handle the errors, where -1 is returned a true value
     * for opening the file */
    if (result_dict < -1 && result_tile < -1) {
        error_print("Failed to load data.\n");
        return EXIT_FAILURE;
    }

    /* display a welcome message */
    normal_print("Please wait while we load the dictionary...\n");
    /*tokenise_tokens(&tilelist, fp_read_tile);*/
    /* Source code on strtol adapted from StackOverflow
     * Author: Unknown
     * Source:
     * https://stackoverflow.com/questions/13399594/how-to-extract-numbers-from-string-in-c
     * Date: 28th July 2018.*/
    /* extract the seed */
    srand(time(NULL));
    /* if the seed has been provided by the user, extract the
     * number from the string provided - please note that I am not
     * using strtoint as we need a long int */
    /* We test whether the 4th file exists*/
    if (argv[3] != NULL && *rand_str && strlen(rand_str) < 10) {
        if (isdigit(*rand_str)) {
            long convert = strtol(rand_str, &rand_str, 10);
            /*randomise = rand() % convert;*/
            normal_print("Using seed %ld\n", convert);
            /* For now we limit the seed number length to 10*/
        } else {
            error_print("Seed number is too long.\n");
            return EXIT_FAILURE;
            /*rand_str++;*/
        }
    } else {
        /* if the seed is not provided, generate the seed for the
         * current second */
        /* start the random number generator */
        randomise = rand();
        /* output the seed being used */
        normal_print("Using seed %ld\n", randomise);
    }

    /* load the dictionary file */
    result_dict = load(&wordlist, fp_read_dict);
    /*result_tile = load(&wordlist, fp_read_tile);*/
    fclose(fp_read_dict);
    fclose(fp_read_tile);
    /* wordlist_add(&wordlist, );*/
    /* play the game :) */
    while (!quit) {
        print_wordlist(&wordlist);
        /* free memory */
        wordlist_free(&wordlist);
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
