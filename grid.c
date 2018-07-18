#include <stdio.h>
#include <stdlib.h>

#define MAXROW 5
#define MAXCOL 5

int main(void)
{
    int i;
    int j;
    for(i = 0; i <= MAXROW; i++) 
    {
        for(j = 0; j <= MAXCOL; j++)
        {
            printf("|\n");
        }
    }
    return EXIT_SUCCESS;
}


/*
void rowHeading(int row[][MAXROW])
{
    unsigned rowNum, countRow;
    for(
}

void columnHeading(int col[][MAXCOL])
{

}
*/
