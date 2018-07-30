/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/

#include "io.h"
#include "game.h"
#include "tile_list.h"

/******************************************************************************
 * the io module should contain the logic for all io functions, both for
 * loading from a file and output to the screen / input from the keyboard. Some
 * functions have been provided here to give you a start.
 *****************************************************************************/

/**
 * array that contains the color strings for each color available in the
 * game
 **/
const char* color_strings[] = {COLOR_RED,   COLOR_GREEN,   COLOR_YELLOW,
                               COLOR_BLUE,  COLOR_MAGENTA, COLOR_CYAN,
                               COLOR_RESET, NULL};

/**
 *  clears the buffer when there is a buffer overflow of input
 **/
void read_rest_of_line(void) {
    int ch;
    while (ch = getc(stdin), ch != '\n' && ch != EOF)
        ;
    clearerr(stdin);
}

/* Source code adapted from getInteger-advanced
 * Author: Paul Miller
 * Source:
 * https://github.com/muaddib1971/c_examp/blob/master/examples/BasicIO/getInteger-basic.c
 * Date: 29th July 2018.*/
BOOLEAN get_int(int* integer, const char* prompt) {
    char input[MAX_INT_LEN + EXTRACHARS];
    int int_result = 0;
    char* end;

    /* Provide a custom input*/
    printf("%s", prompt);

    /* We accept input and then remove any trailing new line */
    fgets(input, MAX_INT_LEN + EXTRACHARS, stdin);
    if (input[strlen(input) - 1] != '\n') {
        read_rest_of_line();
    } else {
        input[strlen(input) - 1] = '\0';
        int_result = (int)strtol(input, &end, 0);
        if (*end != 0) {
            error_print("Input was not numeric.\n");
            return IR_RTM;
        } else if (int_result > MAX_PLAYERS) {
            error_print("Input is outside of 6 players.\n");
            return IR_RTM;
        } else {
            return EXIT_SUCCESS;
        }
    }
    *integer = int_result;
}

/* Compares the first and second word in the qsort function*/
int word_compare(const void* first, const void* second) {
    return strcmp(first, second);
}

int word_count(FILE* file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n')
            ;
        count++;
    }
    return count;
}
/**
 * loads the word list (dictionary of allowed words) into a linked list of
 * words. You should open the file then read in each line into a node in
 * the word list. Don't forget to validate each action and remove the
 * newline characters as you load the data in. Also, don't forget to validate
 * that the whole word has been read an d remove the newline at the end of
 * each line.
 **/
BOOLEAN load_word_list(const char fname[], struct word_list* wordlist) {
    struct word_node* node;
    FILE* file;
    char list[NUM_LETTERS][NUM_LETTERS];
    size_t word_size;
    int i;
    char ch;

    file = fopen(fname, "r");
    /* Error checking for an empty file and for word length for
    dictionary files */
    if (file == NULL) {
        error_print("Unable to open %s file.\n", file);
        return EXIT_FAILURE;
    } else if (strcmp(fname, "words.len5") == 0 &&
               strlen(list[word_size]) > 5) {
        error_print("Word length too big for %s\n", fname);
        return EXIT_FAILURE;
    } else if (strcmp(fname, "words.len7") == 0 &&
               strlen(list[word_size]) > 7) {
        error_print("Word length too big for %s\n", fname);
        return EXIT_FAILURE;
    } else if (strcmp(fname, "words.len10") == 0 &&
               strlen(list[word_size]) > 10) {
        error_print("Word length too big for %s\n", fname);
        return EXIT_FAILURE;
    } else if (strcmp(fname, "words.len12") == 0 &&
               strlen(list[word_size]) > 12) {
        error_print("Word length too big for %s\n", fname);
        return EXIT_FAILURE;
    } else {
        /* Source code on cleaning new line and sorting list based from
         * StackOverflow Author: Unknown Source:
         * https://stackoverflow.com/questions/31751782/qsort-array-of-strings-in-alphabetical-order
         * Date: 29th July 2018.*/
        /* We store 100 words from the list for now, since we don't want to
         * overload the system */
        while (word_size < NUM_LETTERS &&
               fgets(list[word_size], sizeof(*list), file) != NULL) {
            /* We store the newline string and if it exists we remove the
             * trailing line*/
            char* newline = strchr(list[word_size], '\n');
            if (newline != NULL) {
                *newline = '\0';
            }
            if (*(list[word_size])) {
                ++word_size;
            }
        }
        /* Then outside the loop we sort the array*/
        qsort(list, word_size, sizeof list[0], word_compare);
        /*Debugging*/
        /*
        for (i = 0; i < word_size; i++) {
            normal_print("%d: %s\n", i, list[i]);
        }*/
        /*We free each string*/
    }
    fclose(file);
    return EXIT_SUCCESS;
}

/**
 * loads the tiles and their values as well as the count of how many
 * should be created
 **/
BOOLEAN load_scores(const char fname[], struct tile_list** lettermap,
                    struct tile_list** fulllist) {
    return FALSE;
}

/**
 * displays the board with its current contents. As the cells of the board
 * contain both a char and a color, you need to display the char in the color
 * indicated by the color element of the cell. You must use the provided
 * color_strings array to retrieve the color codes to display the strings
 * in the right color.
 **/
void display_board(const struct board* theboard) {}

/**
 * display the hand in a table. Please see the sample executable / the
 * assignment specification for the expected format of this output
 **/
void print_hand(struct tile_list* curhand) {}

/**
 * prints out text to stdout
 **/
int normal_print(const char format[], ...) {
    int charcount;
    va_list arglist;
    /* extract the argument list */
    va_start(arglist, format);
    /* send to output */
    charcount = vprintf(format, arglist);
    /* all done */
    va_end(arglist);
    return charcount;
}

/**
 * prints output to stderr
 **/
int error_print(const char format[], ...) {
    va_list arglist;
    int charcount = 0;
    /* grab the arguments */
    va_start(arglist, format);
    /* send them to stderr */
    charcount += vfprintf(stderr, format, arglist);
    /* all done */
    va_end(arglist);
    return charcount;
}

/**
 * prints out the final scores for each player to stdout, sorted from highest
 * scoring player to lowest scoring player
 **/
void print_finscores(struct game* thegame) {}
