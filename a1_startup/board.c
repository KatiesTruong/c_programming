/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "board.h"
#include "io.h"
/**
 * This file contains the implementation of the functions that manipulates the
 * board type
 **/

/**
 * initialise the board to be an empty board
 **/
/*void init_board(board aboard) {
     Board structure adapted from:
     https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-03/matrix_add.c
     Date: 13th June 2018.

}*/

void init_board(board aboard) {
    int row;
    int y_axis, x_axis;
    /* Sample tokens, change later to C_EMPTY*/
    /*char tokens[] = " ";*/
    /* For loop row plays once */
    for (row = 0; row < 1; row++) {
        /* Remove 0 with conditional statement and replace with
        "  |"*/
        normal_print("  |");
        /* loop for horizontal row */
        /* Note that BOARDHEIGHT is constant 15*/
        /* The conditionals are printing the | closer
         * to the number that is a double digit */
        for (x_axis = 1; x_axis <= BOARDHEIGHT; x_axis++) {
            if (x_axis != 0 && x_axis > 9) {
                normal_print("%d |", x_axis);
            } else if (x_axis < 9) {
                normal_print(" %d |", x_axis);
            }
        }
        normal_print("\n");
        /* loop for vertical row and cells, decrementing from 15 to 1 */
        for (y_axis = BOARDHEIGHT; y_axis >= 1; y_axis -= 1) {
            if (y_axis < 9) {
                normal_print(
                    "----------------------------------------------------------"
                    "-\n");
                /* Note that game_tokens[0] refers to C_EMPTY or " "*/
                normal_print(
                    "%d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0], game_tokens[0],
                    game_tokens[0], game_tokens[0]);
                /* Pushing the | closer to the number to the left
                 * when it's a double digit */
            } else if (y_axis > 9) {
                normal_print(
                    "----------------------------------------------------------"
                    "-\n");
                normal_print(
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
    /* Debug for tokens */
    /* normal_print("%s\n", game_tokens[1]);*/
}
