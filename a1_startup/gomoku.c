/******************************************************************************


 * Student Name    : Katies Truong
 * RMIT Student ID : s36701053
 * COURSE CODE     : CPT220
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "gomoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
/**
 * The main function - the main entry point into your program
 **/
int main(void) {
    /* you should treat the comments in this function as a hint on how to
     * get started. You should start by getting a menu working that behaves
     * the same as the sample executable.
     */
    /* enum cell board[BOARDHEIGHT][BOARDWIDTH]; */
    /* Initialise main menu */
    menu();
    /* initialise the random number generator for your program */
    /* display the menu continuously until the user decided to quit the
     * program
     */
    /* display the menu and get the choice from the user */
    /* based on the choice the user made you should:
     */
    /* play the game */
    /* quit the program */
    return EXIT_SUCCESS;
}

/* Create menu function */
int menu() {
    /* struct game newgame; */
    /* enum board[BOARDHEIGHT][BOARDWIDTH]; */

    BOOLEAN exit = FALSE;
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
        /* Conditional statements on buffer overflow based on:
         * Author: Paul Miller
         * Source: https://github.com/muaddib1971/c_examp/blob/master/examples/BasicIO/getString-basic.c
         * Date: 11th June 2018. */
        if (text_input[strlen(text_input) - 1] != '\n') {
            error_print("Input line is too long\n");
            read_rest_of_line();
        } else {
            text_input[strlen(text_input) - 1] = '\0';
            exit = TRUE;
        }

        /* Input validation for quitting or playing*/
        if (strstr(text_input, play) != NULL) {
            normal_print("Continue...\n");
            exit = TRUE;
        } else if (strstr(text_input, quit) != NULL) {
            normal_print("Quitting...\n");
            exit = FALSE;
            return QUIT;
        } else {
            error_print("Invalid input.\n");
        }
        /* checks for true value */
    /* Change player names to struct player player_one, player_two
     * then call them with player_one.name, player_two.name */
    /* Called functions to initialise game and the board and then display*/
    } while (!exit);
    play_game();
    return EXIT_SUCCESS;
}
