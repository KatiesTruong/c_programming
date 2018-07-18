#include <stdio.h>
#include <stdlib.h>
#define MESSAGE "HELLO WORLD\n"

#if 0
void start() 
{
    /* Does some initialisation of the system */
    int result = main();
    exit(result);
}
#endif

int main(void)
{
    /* outputs the message defined at the top of this program */
    printf(MESSAGE);
    return EXIT_SUCCESS;
    /*
        exit(EXIT_SUCCESS);
    */
}
