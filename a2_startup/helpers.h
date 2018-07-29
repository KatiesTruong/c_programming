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
#define WORD_LEN 12
#define EXTRACHARS 2

/* publicly used functions */
FILE* file_open(char* file);
FILE* file_write(char* file);
#endif
