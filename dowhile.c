#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int a = 0;
    do
        printf("%d\n", a);
    while(++a<50);
#if 0
    while(1==0);
#endif
    return EXIT_SUCCESS;
}
