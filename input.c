#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void)
{
    char userInput[64];
    printf("Starting program....\n");
    /* fgets(userInput, 64, stdin);*/
    while(fgets(userInput, 64, stdin)) 
    {
        printf("userInput: %s", userInput);

        /* If the user presses 0 they quit the program*/
        if(strncmp(userInput, "quit", 2) == 0) {
            printf("Breaking....\n");
            return EXIT_FAILURE;
        }
    }
    printf("Program Quit....\n");
    return 0;
}
