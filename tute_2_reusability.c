#include <stdio.h>
#include <stdlib.h>
#define BASE 2
#define LIMITNUM 13

int main(void)
{
    int i;
    int e = 1;
    for(i = 0; i <= LIMITNUM; i++)
    {
        printf("%d to the power of %d = %d\n", BASE, i, e);
        e *= BASE;
    }
    return EXIT_SUCCESS;
}
