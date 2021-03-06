/******************************************************************************
 * Student Name    : Katies Truong
 * RMIT Student ID : s3671053
 * COURSE CODE     : CPT220
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "io.h"
#include "player.h"
#include "shared.h"

#define INPUTLIMIT 1
#define EXTRACHARS 2
#define QUIT 0
/**
 * This is the header file for the main module. It really just pulls together
 * the header files required by the main function.
 **/

/* Create menu function */
int menu() {
    struct game newgame;
    /* enum board[BOARDHEIGHT][BOARDWIDTH]; */

    BOOLEAN check = FALSE;
    char play[] = "1";
    char quit[] = "2";
    char text_input[INPUTLIMIT + EXTRACHARS];

    /* do while loop for main menu */
    do {
        normal_print("Welcome to Gomoku\n");
        normal_print("================\n");
        normal_print("1) Play the game\n");
        normal_print("2) Quit the game\n");
        normal_print("Enter your choice: ");
        fgets(text_input, INPUTLIMIT + EXTRACHARS, stdin);
        /* Stops after error need to find a way to make it
        loop. */
        /* Conditional statements on buffer overflow based on:
         * Author: Paul Miller
         * Source: https://github.com/muaddib1971/c_examp/blob/master/examples/BasicIO/getString-basic.c
         * Date: 11th June 2018. */
        if (text_input[strlen(text_input) - 1] != '\n') {
            error_print("Input line is too long\n");
            read_rest_of_line();
        } else {
            text_input[strlen(text_input) - 1] = '\0';
            check = TRUE;
        }

        /* Input validation for quitting or playing*/
        if (strstr(text_input, play) != NULL) {
            normal_print("Continue...\n");
            check = TRUE;
        } else if (strstr(text_input, quit) != NULL) {
            normal_print("Quitting...\n");
            check = FALSE;
            return QUIT;
        } else {
            error_print("Invalid input.\n");
            continue;
        }
        /* checks for true value */
    } while (!check);
    /* Change player names to struct player player_one, player_two
     * then call them with player_one.name, player_two.name */
    /* Called functions to initialise game and the board and then display*/
    init_game(&newgame);
    /* display_board(board); */
    return EXIT_SUCCESS;
}
