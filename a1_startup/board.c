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
void init_board(board aboard) {
    int board[BOARDHEIGHT][BOARDWIDTH] = {
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY}};
}

/* Displays board */
void display_board(board aboard) {
    int row;
    int y_axis, x_axis;
    /* Sample tokens, change later to C_EMPTY*/
    char tokens[] = " ";
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
        /* loop for vertical row*/
        for (y_axis = 1; y_axis <= BOARDHEIGHT; y_axis++) {
            if (y_axis < 9) {
                printf(
                    "----------------------------------------------------------"
                    "-\n");
                printf(
                    "%d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens);
            } else if (y_axis > 9) {
                printf(
                    "----------------------------------------------------------"
                    "-\n");
                printf(
                    "%d| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens);
            }
        }
        printf("\n");
    }
}
/* Prints board to the screen */
/*void display_board(int board[BOARDHEIGHT][BOARDWIDTH])
{
    unsigned y_axis, x_axis;
    int row;
    for(row = 0; row <= 10; row++)
    {
        for(y_axis = 0; y_axis < 10; y_axis++)
        {
            normal_print("%d \n", y_axis);
        }
        normal_print("\n");
        for(x_axis = 0; x_axis < 10; x_axis++)
        {
            normal_print("%d", x_axis);

        }
        normal_print("\n");
    }
}*/
