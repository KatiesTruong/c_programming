#include <stdio.h>
#include <stdlib.h>

#define PRINTED_CHAR "* "
#define MAXSTARS 10
int main(void)
{
    int row, column;
    for(row = 1; row <= MAXSTARS; row++)
    {
        for(column = 1; column <= row; column++)
        {
            printf(PRINTED_CHAR);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
