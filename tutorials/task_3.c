#include <stdio.h>
#include <stdlib.h>
#include "tute_2.h"

int main(void)
{
    int row, column, space;
    for(row = 1; row <= MAX_CHAR; row++)
    {
        for(space = 1; space <= MAX_CHAR - row; space++)
        {
            printf(PRINTED_SPACE);
        }
        for(column = 1; column <=(2 * row) - 1; column++)
        {
            printf(PRINTED_CHAR_3);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
