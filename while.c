#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int j = -50, i = 50;
    while(j++)
    {
        printf("%d\n", j);
    }
    while(--i)
    {
        printf("%d\n", i);
    }
    return EXIT_SUCCESS;
}
