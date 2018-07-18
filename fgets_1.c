#include <stdio.h>
#include <stdlib.h>

#define LSIZE 1024
#define EXTRACHARS 2

int main(void)
{
    char textInput[LSIZE + EXTRACHARS];
    /* fetch up to 1024 chars not counting the terminating characters
    of \n\0
    */
    while(fgets(textInput, LSIZE + EXTRACHARS, stdin) != NULL)
    {
        puts(textInput); /* display it if found */
    }   /* loop back until EOF*/
    return EXIT_SUCCESS;
}
