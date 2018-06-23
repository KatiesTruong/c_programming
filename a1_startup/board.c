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
     *https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-03/matrix_add.c
     *Date: 13th June 2018. */
    board new_board = {
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
         C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY},
        {C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY,
          C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY, C_EMPTY}
    };
    /*Display board debug*/
    display_board(new_board);
}
