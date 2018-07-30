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
FILE* tokenise_tokens(FILE* file) {
    /* When tokenising with strtok we use strcpy from the mystrdup function to
     * avoid modification errors when copying a string to the temporary buffer.
     * Source code on mystrdup is acknowledged from the helpers.c file*/
    struct tile_list* tilelist;
    struct tile* new;
    struct game* newgame;
    char buffer[BUFFER_SIZE];
    char* token;
    char* cpy_token = mystrdup(buffer);
    long int num_token;
    char* endptr;
    /* Error checking*/
    if (file == NULL) {
        error_print("Unable to open %s file\n", file);
        exit(EXIT_FAILURE);
    } else {
        while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
            token = strtok(buffer, DELIMS);
            /*num_token = strtol(token, &endptr, 0);
            new->score = num_token;
            new->letter = num_token;
            tilelist->num_tiles = num_token;*/
            while (token != NULL) {
                /* Debugging */
                /* normal_print("%s\n", token);*/
                token = strtok(NULL, DELIMS);
            }
        }
    }
    free(cpy_token);
    fclose(file);
    return file;
}

/* Source code adapted from list.c for account file
 * Author: Paul Miller
 * Source: ~e70949/shared/prog_in_c/tutes/2018sp2week7/solution
 * Date: 29th July 2018.*/

BOOLEAN init_tilelist(struct tile_list* tilelist) {
    tilelist->tiles = (struct tile*)malloc(sizeof(struct tile) * 10);
    /* Error checking */
    if (!tilelist->tiles) {
        error_print("Failed to allocate tile memory.\n");
        return EXIT_FAILURE;
    }
    tilelist->num_tiles = 0;
    tilelist->total_tiles = 10;
    return EXIT_SUCCESS;
}

BOOLEAN add_tiles(struct tile_list* tilelist, struct tile tile) {
    int count;
    if (tilelist->num_tiles == tilelist->total_tiles) {
        void* test = (struct tile*)realloc(
            tilelist->tiles, DOUBLE(tilelist->num_tiles) * sizeof(struct tile));
        if (!test) {
            error_print("Failed to reallocate.\n");
            return EXIT_FAILURE;
        }
        tilelist->tiles = test;
        tilelist->total_tiles = DOUBLE(tilelist->total_tiles);
    }
    for (count = 0; count < tilelist->num_tiles; count++) {
        int back_count;
        for (back_count = tilelist->num_tiles; back_count > count;
             back_count--) {
            tilelist->tiles[count] = tile;
            tilelist++->num_tiles;
            return EXIT_SUCCESS;
        }
    }
    tilelist->tiles[tilelist->num_tiles++] = tile;
    return EXIT_SUCCESS;
}

void free_tiles(struct tile_list* tilelist) {
    assert(tilelist);
    free(tilelist->tiles);
}
