/******************************************************************************
 * Student Name    : Katies Truong
 * RMIT Student ID : s3671053
 * COURSE CODE     : CPT220
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "game.h"
#include <time.h>
#include "io.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * this file contains the implementation of functions for the management of the
 * game
 **/

/**
 * initialises the game to a starting state. You should select a random token
 * for one player and ensure the second player has a different token. You should
 * call init_player() passing in the address of the player, its token, and a
 * pointer to this game. Finally you should initialise the pointers to each
 * player ensuring that a random player is selected to play the game. You should
 * also ensure the board is coorectly initialised through a call to
 * init_board().
 **/
enum input_result init_game(struct game* newgame) {
    int first_player;
    int second_player; 
    int curplayer;

    /* We seed the random number to the UNIX time for rand() to randomise the
     * NUM_PLAYERS(2) between player 1 and 2.*/
    srand(time(NULL));
    /* when number player is randomised as first player(which is 0). Then
     * we set the first init_player to have the white token(which is 1).*/
    /*initialising each player, placed C_WHITE and C_RED for now */
    if ((curplayer = rand() % NUM_PLAYERS) == 0) {
        newgame->current = &newgame->players[1];
        newgame->other = &newgame->players[2];

        newgame->current->token = C_WHITE;
        newgame->other->token = C_RED;
    } else if ((curplayer = rand() % NUM_PLAYERS) == 1){
        newgame->current = &newgame->players[2];
        newgame->other = &newgame->players[1];

        newgame->current->token = C_RED;
        newgame->other->token = C_WHITE;
    }
    /* Initialises the players based on token */
    first_player = init_player(newgame->current, newgame->current->token, newgame, 1);
    second_player = init_player(newgame->other, newgame->other->token, newgame, 2); 

    /* Validates the first turn*/
    if(curplayer == first_player) {
        newgame->current->name[strlen(newgame->current->name)-1]=0;
        normal_print("%s's first turn.\n", newgame->current->name);
    } else if(curplayer == second_player){
        newgame->other->name[strlen(newgame->other->name)-1]=0;
        normal_print("%s's first turn.\n", newgame->other->name);
    }
    /* initialise the board */
    init_board(newgame->gameboard);

    return IR_SUCCESS;
}

/**
 * manages the main game loop - calls init_player to initialise the players and
 * then loops and calls take_turn for the current player and swaps players until
 * a player has won the game
 **/
void play_game(void) {
    /* the game struct that holds the data on the game state */
    struct game curgame;
    /* init the game struct */
    init_game(&curgame);
    /* the main game loop */
    display_board(curgame.gameboard);
    first_round(&curgame);
    display_board(curgame.gameboard);
    /* swap the game pointers */
    swap_players(&curgame.current, &curgame.other);
}

/**
 * swaps the two player pointers for the two players playing the current game
 * (it's a way for us to swap who the current player is). Please note that an
 * implementation that swaps values rather than pointers will not get full marks
 * for this. This function is only worth a few marks but the intellectual
 * content understanding is very important and thus it is worth substantially
 * more than a few lines of code are worth elsewhere in this assignment.
 **/
 /*
  * Swapping pointers adapted from  
  */
  /* Swapping code adapted from the swapping function in call by reference section:
   * Author: Paul Miller
   * Source: https://sites.google.com/a/rmit.edu.au/programming-in-c---notes/home/week-3-problem-solving-and-functional-abstraction/4-functions
   * Date: 3rd July 2018.
   */
void swap_players(struct player** first, struct player** second) {
    struct player *temp  = *first;
    *first = *second;
    *second = temp;
}

/**
 * implements the rules for the first round of the game, the so-called
 * swap2 rules. Please see the assignment specification and game rules for
 * further details.
 **/
 /* Tokenising and delimiters are adapted from:
  * Source: https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-03/strtok_example.c
  * Date: 3rd July 2018.
  */
enum input_result first_round(struct game* thegame) {
    char prompt_token[TOKENINPUT + EXTRACHARS];
    char *token;
    long num_result;
    int num;
    char *end;
    
    while (prompt_token != NULL) {
        normal_print("Please enter a location for a %s token: ", color_strings[thegame->current->token]);
        fgets(prompt_token, TOKENINPUT + EXTRACHARS, stdin);

        prompt_token[strlen(prompt_token) - 1] = '\0';

        /* We validate the input as a string */
        if(!(strstr(prompt_token, "8,8") != NULL)) {
            error_print("Token must be in the centre.\n");
            return FALSE;
        } else {
            token = strtok(prompt_token, DELIMS);
            num_result = strtol(token, &end, 0);
            /* If the numbers are within the range of 0-15, we then convert the long to and int.*/
            if (num_result <= INTMAX && num_result >= INTMIN) {
                num = num_result;
            }
            /* Validate the tokenised integers */
            else if (*end) {
                error_print("Invalid input. Needs to be numeric.\n");
                return FALSE;
            } else if (end == 0) {
                error_print("Cannot leave token empty.\n");
                return FALSE;
            }
            token = strtok(NULL, DELIMS);
            /*return TRUE;*/
            return num;
        }
    }
    /* get_integer(&int_result, TOKENINPUT, prompt_token, INTMIN, INTMAX); */
    return IR_SUCCESS; 
}
