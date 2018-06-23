/******************************************************************************
 * Student Name    : Katies Truong
 * RMIT Student ID : s3671053
 * COURSE CODE     : CPT220
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "player.h"
#include "game.h"
#include "io.h"

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
    char name[NAMELEN + EXTRACHARS];
    /* Initialise the player */
    /* Prompts for player 1 and 2's name, since curplayer->name points to
     * 2 players, we use the playernum to identify each player.*/
    normal_print("Enter player %d's name: ", playernum);
    fgets(name, NAMELEN + EXTRACHARS, stdin);
    strcpy(curplayer->name, name);
    /* Prints out the current player's name's turn */
    if (curplayer->token == C_WHITE) {
        name[strlen(name) - 1] = '\0';
        normal_print("%s plays first.\n", name);
    } else if(curplayer->token == C_RED) {
        name[strlen(name) - 1] = '\0';
        normal_print("%s plays first.\n", name);
    }
    return IR_FAILURE;
}

/**
 * get input for a turn from the user, validate it as a move coordinate and if
 * it is valid, apply the move to the board. If the move is not valid then
 * display an error message but if it is valid return a IR_SUCCESS result. If a
 * user has chosen to quit the game, return IR_RTM.
 **/
enum input_result take_turn(struct player* curplayer) { return IR_FAILURE; }
