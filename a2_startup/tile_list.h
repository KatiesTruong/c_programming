/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "helpers.h"
#include "io.h"
#include "shared.h"
#include "word_list.h"
#ifndef WORDMAP_H
#define WORDMAP_H
#define AL_NUM_LETTERS 26
#define NUM_TILE_DELIMS 2
#define NUM_TILE_TOKENS 3
#define NUM_LETTERS 100
#define DELIMS ","
#define BUFFER_SIZE 1024
/**
 * a tile is a letter and tile pair.
 **/
struct tile {
    /* int is used for letter rather than char in order to consistently
     * use negative numbers
     */
    int letter;
    int score;
};

/**
 * score_count stores both the tile and how many times that tile should occur.
 **/
struct score_count {
    struct tile tile;
    int count;
};

/**
 * global const variable that indicates that an error has occured.
 **/
extern const struct score_count error_score;

struct tile_list {
    struct tile* tiles;
    int num_tiles;
    int total_tiles;
};

/* Public functions*/
FILE* tokenise_tokens(FILE*);
BOOLEAN init_tilelist(struct tile_list*);
BOOLEAN add_tiles(struct tile_list*, struct tile);
void free_tiles(struct tile_list*);
#define DOUBLE(X) ((X) * (X))
#endif
