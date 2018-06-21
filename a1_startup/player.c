/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "player.h"
#include "game.h"

/**
 * this file contains the implementation of the functions for manipulation of
 * the player type
 **/

/**
 * initialises the player passed in so that it has the token specified. You
 * should also prompt the user for this name
 **/
/* Prompting player's name with pointers adapted from personlist files:
 * https://github.com/muaddib1971/c_examp/tree/master/examples/DynAlloc/personlist
 * Date: 20th June 2018.
 */
enum input_result init_player(struct player* curplayer, enum cell token,
                              struct game* thegame, int playernum) {
    /* ATTENTION: Fix problem with double prompts of player names */
    char name[NAMELEN + EXTRACHARS];
    /* Initialise the player */
    /* Prompts for player's name */
    normal_print("Enter first player's name: ");
    fgets(curplayer->name, NAMELEN + EXTRACHARS, stdin);
    strcpy(curplayer->name, name);
    normal_print("Enter second player's name: ", curplayer->name);
    fgets(curplayer->name, NAMELEN + EXTRACHARS, stdin);
    strcpy(curplayer->name, name);
    /* Prints out the current player's name's turn */
    /* use strcpy for the element to name[] */
    return IR_FAILURE;
}

/**
 * get input for a turn from the user, validate it as a move coordinate and if
 * it is valid, apply the move to the board. If the move is not valid then
 * display an error message but if it is valid return a IR_SUCCESS result. If a
 * user has chosen to quit the game, return IR_RTM.
 **/
enum input_result take_turn(struct player* curplayer) { return IR_FAILURE; }
