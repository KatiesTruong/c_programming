/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "io.h"
#include <limits.h>
#include <string.h>
#include "player.h"

/**
 * this file has the implementation functions for input / output. All ouput
 * should happen from this module so that it would be easy to rewrite output
 *to another format, such as a gui application.
 **/

/**
 * The values for the various game tokens as strings. These are in the same
 * order as the cell enumeration. In other words the 0th element is for
 *empty, the first is red and the second is white. The NULL pointer on the
 *end is for the C_INVALID constant
 **/
const char* game_tokens[NUM_TOKEN_TYPES] = {" ", REDCOLOR "o" RESETCOLOR,
                                            WHITECOLOR "o" RESETCOLOR, NULL};

const char* color_strings[NUM_TOKEN_TYPES] = {"Empty", REDCOLOR "red" RESETCOLOR, WHITECOLOR "white" RESETCOLOR, NULL};
/**
 * the read rest of line function - clears the buffer when there is buffer
 *  overflow
 **/
void read_rest_of_line(void) {
    int ch;
    /* read each char in the input buffer until we run out of chars to read
     */
    while (ch = getc(stdin), ch != '\n' && ch != EOF)
        ;
    /* clear the error status on the stdin FILE pointer */
    clearerr(stdin);
}

/**
 * get_integer function is adapted from the getInteger code:
 * Author: Paul Miller
 * Source: https://github.com/muaddib1971/c_examp/blob/master/examples/BasicIO/getInteger-basic.c
 * Date: 5th July 2018.
 **/
#if 0 
 void get_integer(int* num, const unsigned length, const char* prompt, const int min, const int max) {
    int exit = FALSE;
    char int_prompt[TOKENINPUT + EXTRACHARS];
    char *token;
    int int_cast = 0;
    char *end;

    /* We create the prompt interface for the user, then validate and cast the converted string
     * to a long int to an int. */
    do {
        normal_print("%s", prompt);
        fgets(int_prompt, length + EXTRACHARS, stdin);
        int_prompt[strlen(int_prompt) - 1] = '\0';

       /*if (int_prompt[strlen(int_prompt) - 1] != '\n') {
            error_print("Input was too long\n");
        } */

        int_cast = (int) strtol(int_prompt, &end, 0);
        /*token = strtok(int_prompt, DELIMS);*/
        /* Validation */
        /*if (*end != 0) {
            error_print("Input is not a number.\n");
        } else if (int_cast <= min || int_cast >= max) {
            normal_print("Input is outside of the range.\n");
        } else {
            exit = TRUE;
        }*/
    } while (exit == FALSE);
    /* We then proceed to make the casted int called num to be called through the function */
    *num = int_cast;
    normal_print("%d\n", int_cast);
}
#endif 
/* Removes new line that has \n during buffer when fgets() receives a string */
/*ATTENTION FIX */
void remove_newline(char line[]) {
    char end[NAMELEN + EXTRACHARS];
    end[strlen(end) - 1] = '\0';
}

/**
 * print function provided to be able to print from outside this module
 **/
int error_print(const char* format, ...) {
    /* the number of chars printed by this function */
    int charsprinted;
    va_list argvec;
    /* marshall the output for sending to vprintf */
    va_start(argvec, format);
    /* change the color to red and print the Error preambe for an error
     * message */
    charsprinted = fprintf(stderr, REDCOLOR "Error: ");
    /* print the output required by the user */
    charsprinted += vfprintf(stderr, format, argvec);
    /* reset back to the default colour */
    charsprinted += fprintf(stderr, RESETCOLOR);
    /* stop using the stdarg library */
    va_end(argvec);
    return charsprinted;
}

/**
 * print normal output - this function literally just calls printf.
 **/
int normal_print(const char* format, ...) {
    int charsprinted;
    va_list argvec;
    va_start(argvec, format);
    charsprinted = vprintf(format, argvec);
    va_end(argvec);
    return charsprinted;
}

/* Function that initialises the board's header row */
void board_header() {
    int row;
    /* Remove 0 with conditional statement and replace with "  |" */
    /* Note that BOARDHEIGHT is constant 15 */
    normal_print("  |");
    for (row = 1; row <= BOARDHEIGHT; row++) {
        if (row != 0 && row > 9) {
            normal_print("%d |", row);
        } else if (row < 9) {
            normal_print(" %d |", row);
        }
    }
    normal_print("\n");
}

/* Function for iterating the lines and cells in an empty board */
void board_cell_loop() {
    int row;
    /* int tokens; */

    /* Loops for cells and lines*/
    for (row = 15; row >= 1; row -= 1) {
        if (row < 9) {
            normal_print(
                "----------------------------------------------------------"
                "-\n");
            /* Note that game_tokens[0] refers to C_EMPTY or " "*/
            normal_print(
                "%d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                "| %s | %s | %s |\n",
                row, game_tokens[0], game_tokens[0], game_tokens[0],
                game_tokens[0], game_tokens[0], game_tokens[0], game_tokens[0],
                game_tokens[0], game_tokens[0], game_tokens[0], game_tokens[0],
                game_tokens[0], game_tokens[0], game_tokens[0]);
        } else if (row > 9) {
            normal_print(
                "----------------------------------------------------------"
                "-\n");
            normal_print(
                "%d| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                "| %s | %s | %s |\n",
                row, game_tokens[0], game_tokens[0], game_tokens[0],
                game_tokens[0], game_tokens[0], game_tokens[0], game_tokens[0],
                game_tokens[0], game_tokens[0], game_tokens[0], game_tokens[0],
                game_tokens[0], game_tokens[0], game_tokens[0]);
        }
    }
}

/* Displays board */
/* Needs to display when tokens are inserted */
void display_board(board aboard) {
    int row;
    /* Sample tokens, change later to C_EMPTY*/
    /*char tokens[] = " ";*/
    /* For loop row plays once */
    for (row = 0; row < 1; row++) {
        /* Calls the board header */
        board_header();
        /* calls for board cell loop */
        board_cell_loop();
    }
}
