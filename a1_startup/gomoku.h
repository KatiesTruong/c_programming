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
         /* enum cell board[BOARDHEIGHT][BOARDWIDTH];*/
         struct game newgame;

         BOOLEAN check = FALSE;
         char play[] = "1";
         char quit[] = "2";
         char text_input[INPUTLIMIT+EXTRACHARS];

         /* char curr_player[NAMELEN+EXTRACHARS], second_player[NAMELEN+EXTRACHARS]; */
         /* do while loop for main menu */
         do
         {
            normal_print("Welcome to Gomoku\n");
            normal_print("================\n");
            normal_print("1) Play the game\n");
            normal_print("2) Quit the game\n");
            normal_print("Enter your choice: ");
            fgets(text_input, INPUTLIMIT+EXTRACHARS, stdin);
            /* Stops after error need to find a way to make it
            loop. */
            /* Conditional statements on buffer overflow based on:
             * https://github.com/muaddib1971/c_examp/blob/master/examples/BasicIO/getString-basic.c
             * Date: 11th June 2018. */
            if(text_input[strlen(text_input) - 1] != '\n')
            {
                error_print("Input line is too long\n");
                read_rest_of_line();
            }
            else
            {
                text_input[strlen(text_input) - 1] = '\0';
                check = TRUE;
            }

            /* Input validation for quitting or playing*/
            if(strstr(text_input, play) != NULL)
            {
                normal_print("Continue...\n");
                check = TRUE;
            }
            else if(strstr(text_input, quit) != NULL)
            {
                normal_print("Quitting...\n"); 
                check = FALSE;
                return 0;
            }
            else
            {
                error_print("Invalid input.\n");
                continue;
            }
            /* checks if string compare are the same as play which is 1*/
         } while(!check);
         /* Change player names to struct player player_one, player_two
          * then call them with player_one.name, player_two.name */
         /* init_player(&curplayer, token, &thegame, 1); */
         /*normal_print("Please enter player 1's name: ");
         fgets(first_player, NAMELEN+EXTRACHARS, stdin);
         normal_print("Please enter player 2's name: ");
         fgets(second_player, NAMELEN+EXTRACHARS, stdin);
         normal_print("%s plays first.\n", first_player);*/
         init_game(&newgame);
         return EXIT_SUCCESS;
}
