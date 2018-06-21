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

/**
 * this file has the implementation functions for input / output. All ouput
 * should happen from this module so that it would be easy to rewrite output to
 * another format, such as a gui application.
 **/

/**
 * The values for the various game tokens as strings. These are in the same
 * order as the cell enumeration. In other words the 0th element is for empty,
 * the first is red and the second is white. The NULL pointer on the end is for
 * the C_INVALID constant
 **/
const char* game_tokens[NUM_TOKEN_TYPES] = {" ", REDCOLOR "o" RESETCOLOR,
                                            WHITECOLOR "o" RESETCOLOR, NULL};

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

/* Displays board */
/* Needs to display when tokens are inserted */
void display_board(board aboard) {
    int row;
    int y_axis, x_axis;
    /* Sample tokens, change later to C_EMPTY*/
    /*char tokens[] = " ";*/
    /* For loop row plays once */
    for (row = 0; row < 1; row++) {
        /* Remove 0 with conditional statement and replace with
        "  |"*/
        printf("  |");
        /* loop for horizontal row */
        /* Note that BOARDHEIGHT is constant 15*/
        for (x_axis = 1; x_axis <= BOARDHEIGHT; x_axis++) {
            if (x_axis != 0 && x_axis > 9) {
                printf("%d |", x_axis);
            } else if (x_axis < 9) {
                printf(" %d |", x_axis);
            }
        }
        printf("\n");
        /* loop for vertical row and cells*/
        for (y_axis = 1; y_axis <= BOARDHEIGHT; y_axis++) {
            if (y_axis < 9) {
                printf(
                    "----------------------------------------------------------"
                    "-\n");
                /* Note that game_tokens[0] refers to C_EMPTY or " "*/
                printf(
                    "%d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0]);
            } else if (y_axis > 9) {
                printf(
                    "----------------------------------------------------------"
                    "-\n");
                printf(
                    "%d| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0]);
            }
        }
    }
}
