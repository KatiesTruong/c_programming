/******************************************************************************
 * Student Name    : Katies Truong
 * RMIT Student ID : s3671053
 * COURSE CODE     : CPT220
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "game.h"
#include "io.h"
#include "player.h"
#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INPUTLIMIT 1
#define EXTRACHARS 2
/**
 * This is the header file for the main module. It really just pulls together
 * the header files required by the main function.
 **/

 /* Create menu function */
int menu()
{
         int check = FALSE;
         char play[] = "1";
         char quit[] = "2";
         char text_input[INPUTLIMIT+EXTRACHARS];
         char curr_player[NAMELEN+EXTRACHARS], second_player[NAMELEN+EXTRACHARS];
         /* do while loop for main menu */
         do
         {
            normal_print("Welcome to Gomoku\n");
            normal_print("================\n");
            normal_print("1) Play the game\n");
            normal_print("2) Quit the game\n");
            fgets(text_input, INPUTLIMIT+EXTRACHARS, stdin);
            /* Stops after error need to find a way to make it
            loop. */
            if(text_input[strlen(text_input) - 1] != '\n')
            {
                error_print("Input line is too long\n");
                read_rest_of_line();
            }
            else if(strstr(text_input, quit) != NULL)
            {
                normal_print("Quitting\n");
                check = FALSE;
                return 0;
            }
            else if(strstr(text_input, play) != NULL)
            {
                normal_print("Continue...\n");
                check = TRUE;
            }
            else if(text_input == NULL)
            {
                error_print("Invalid input.\n");
                continue;
            }
            else
            {
                text_input[strlen(text_input) - 1] = '\0';
                check = TRUE;
            }

            /* Input validation for quitting or entering
            single chars*/
           
            /* checks if string compare are the same as play which is 1*/
         } while(!check);
         normal_print("Please enter player 1's name: \n");
         fgets(curr_player, NAMELEN+EXTRACHARS, stdin);
         normal_print("Please enter player 2's name: \n");
         fgets(second_player, NAMELEN+EXTRACHARS, stdin);
         return EXIT_SUCCESS;
}
