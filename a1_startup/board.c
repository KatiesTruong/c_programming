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
    /*Board structure adapted from:
     * Author: Paul Miller
     * Source: ~e70949/shared/prog_in_c/assignments/parta_sol
     * Date: 6th July 2018. */
     memset(aboard, 0, sizeof(enum cell) * BOARDWIDTH * BOARDHEIGHT);
}


