/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/

#include "tile_list.h"

/******************************************************************************
 * the tile list module manages the tile list which might behave like a tile map
 * (mapping between a letter and a score) or it might be a list which that can
 * be added to or deleted from (such as a tile deck or tile hand). You are
 *required to create the functions for this list.
 *****************************************************************************/
int tokenise_tokens(struct tile_list* tilelist, FILE* fp_read) {
    FILE* fp_read_tile;
    char buffer[BUFFER_SIZE];
    char* token;
    /*Tokenise loop*/
    while (fgets(buffer, BUFFER_SIZE, fp_read_tile) != NULL) {
        token = strtok(buffer, DELIMS);
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, DELIMS);
        }
    }
}
