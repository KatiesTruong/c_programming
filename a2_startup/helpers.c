/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "helpers.h"
/******************************************************************************
 * the helpers module is a great place to store functions that don't logically
 * "live" in another module.
 *****************************************************************************/

/* Source codes on file open and write are adapted from fsupport.c
 * Author: Paul Miller
 * Source:
 * https://github.com/muaddib1971/c_examp/blob/master/lectures/Week-05/fsupport.c
 * Date: 19th July 2018.*/
/* Function that opens files and outputs error when it fails */

FILE* file_open(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        /* return file when succeeds to open*/
        fprintf(stderr, "Failed to open %s file: %s\n", file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return file;
}

/* Function that opens and write files */

FILE* file_write(char* file_name) {
    FILE* file;
    if ((file = fopen(file_name, "w")) == NULL) {
        fprintf(stderr, "Failed to open %s file: %s\n", file, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return file;
}

/* Source code on strdup is adapted from account.c file
 * Author: Paul Miller
 * Source: ~e70949/shared/prog_in_c/tutes/2018sp2/week7/solution
 * Date: 29th July 2018.*/

char* mystrdup(const char str[]) {
    char* newstr = malloc((strlen(str) + 1) * sizeof(char));
    if (!newstr) {
        return NULL;
    }
    strcpy(newstr, str);
    return newstr;
}
