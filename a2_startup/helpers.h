/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "shared.h"

#ifndef HELPERS_H
#define HELPERS_H

/* publicly used functions */
FILE* file_open(char* file);
FILE* file_write(char* file);
int load(struct word_list*, FILE* fp_read);
void* safe_malloc(size_t, unsigned long);

/* provide line numbers to safe_malloc through a macro */
#define safemalloc(size) safe_malloc(size, __LINE__)
#endif
