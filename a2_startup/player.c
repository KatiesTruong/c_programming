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

/******************************************************************************
 * the player module manages the player struct. There are required functions
 * provided such as new_players(), init_player(), take_turn(),
 * shuffle_players(), player_sort() and some comparison functions for players.
 * You should add additional functions for managing of players if you need to.
 *****************************************************************************/

/**
 * allocates a players array of the size specified. It allocates a random color
 * for each player and then calls init_player() on each player, passing in the
 * required arguments
 **/
struct player* new_players(int num_players, struct game* thegame,
                           enum input_result* status) {
    struct player* new;
    int player_color;
    int cur_player;
    int count;
    /* We safely malloc the struct player before we allocate players to array */
    new = safemalloc(sizeof(struct player));
    /* We extract random seed */
    srand(time(NULL));
    player_color = rand() % MAX_PLAYERS + 1;
    while (num_players == MAX_PLAYERS) {
        new->thegame = NULL;
        new->score = 0;
        /* Loop through up to 6 players and increment the colors
          while comparing for each player for their colors.*/
        for (count = 0; count < MAX_PLAYERS; count++) {
            player_color++;
            if (player_color == C_RED) {
                player_color = C_RED;
            } else if (player_color == C_GREEN) {
                player_color = C_GREEN;
            } else if (player_color == C_YELLOW) {
                player_color = C_YELLOW;
            } else if (player_color == C_BLUE) {
                player_color = C_BLUE;
            } else if (player_color == C_MAGENTA) {
                player_color = C_MAGENTA;
            } else if (player_color == C_CYAN) {
                player_color = C_CYAN;
            }
        }
        cur_player = rand() % MAX_PLAYERS;
        thegame->players = &thegame->players[cur_player];
        cur_player = (cur_player + 1 % MAX_PLAYERS);

        return new;
    }
    return EXIT_SUCCESS;
}

/**4

 * Initialise the data for a player. this includes prompting for the name
 * of a player, and filling the starting hand for the using from the tile
 * deck, as well as setting the color and the game pointer and set the score to
 * 0.
 **/
enum input_result init_player(struct player* curplayer, int playernum,
                              enum color color, struct game* thegame) {
    char name[NAMELEN + EXTRACHARS];
    /* Error checking */
    normal_print("Please enter player %d's name: ", playernum);
    fgets(name, NAMELEN + EXTRACHARS, stdin);
    strcpy(curplayer->name, name);
    return EXIT_SUCCESS;
}

/**
 * This is the function that implements each player turn. Firstly, the word to
 * player is prompted for - the word cannot be any longer than the width of
 * the board, of course. Display the board, prompt for the coordinates of
 * the move in the form of x:y:d where x and y are the starting coordinates of
 * the word and d is the dimension of the word - either h or v (case
 * insensitive). It must be apparent from the prompt the name and color of the
 * player who is taking the current turn.
 *
 * Next, use the functions implemented in the rules module to validate
 * and apply the changes to the board.
 **/
enum input_result take_turn(struct player* curplayer, BOOLEAN isfirst) {
    /* you'll need to allocate and free this on every turne */
    char* word;
    return IR_FAILURE;
}

/**
 * shuffle the player so they are ordered in a different order to the order
 * they were entered as part of initialisation
 **/
void shuffle_players(struct player players[], int num_players) {}

/**
 * sorts the players in the player list in some order
 **/
void player_sort(struct player* players, int num_players,
                 int (*cmp)(const struct player*, const struct player*)) {}

/**
 * when finalising the scores, players are sorted by score from top to bottom
 * to print out at the end of a game
 **/
int player_cmp(const struct player* first, const struct player* second) {
    return EOF;
}

/**
 * in the random shuffle, we randomly "sort" elements according to the result
 * returned from rand()
 **/
int player_shuffle_cmp(const struct player* first,
                       const struct player* second) {
    return EOF;
}
