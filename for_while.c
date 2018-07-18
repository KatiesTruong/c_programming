#include <stdio.h>
#include <stdlib.h>

void doit() {}
int main(void)
{
    int i=5;
    doit();
    /*
    while(1)
    {
        printf("loop\n");
    }
    */
    for(i=0;i<5;i++)
    {
        printf("another loop\n");
    }
    return EXIT_SUCCESS;
}
