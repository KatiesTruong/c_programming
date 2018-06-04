/******************************************************************************
 * Student Name    : Katies Truong
 * RMIT Student ID : s36701053
 * COURSE CODE     : CPT220
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "gomoku.h"
/**
 * The main function - the main entry point into your program
 **/
int main(void)
{
        /* you should treat the comments in this function as a hint on how to 
         * get started. You should start by getting a menu working that behaves
         * the same as the sample executable. 
         */
         /* initialise the options. Use magic number for debugging purposes, will remove
         later in development.*/
         char options = '1';
         /* do while loop for main menu */
        
         printf("Welcome to Gomoku\n");
         printf("================\n");
         printf("1) Play the game\n");
         printf("2) Quit the game\n");
         if(options == '1')
            printf("Success!\n");
         else if(options == '2')
            printf("Quitting...\n");
         else
            printf("Invalid choice. Please choose again.\n");
        /* initialise the scoreboard to an empty scoreboard */
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
