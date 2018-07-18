#include <stdio.h>
#include <stdlib.h>

#define PRINTED_CHAR "*"
#define PRINTED_SPACE " "
#define MAX_NUM 10

int main(void)
{
    int row, column, space;
    for(row = 1; row <= MAX_NUM; row++)
    {
        for(space = 1; space <= MAX_NUM - row; space++)
        {
            printf(PRINTED_SPACE);
        }
        for(column = 1 ; column <= row; column++)
        {
            printf(PRINTED_CHAR);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
