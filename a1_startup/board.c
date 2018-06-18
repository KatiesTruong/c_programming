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
    int current_board[BOARDHEIGHT][BOARDWIDTH] = {
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY}};
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
