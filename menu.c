#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define STRING 1
#define EXTRACHARS 2

void read_rest_of_line();

typedef enum 
{
    FALSE,
    TRUE
} BOOLEAN;
/* Has double outputs of a printed statement, most likely due to buffer issues.
Will use read_rest_of_line to fix it.*/
int main(void)
{
   /* int check = FALSE;*/
    char* play = "1";
    char* quit = "2";
    char text_input[10];
    
    printf("Enter 1 to play, 2 to quit:\n");
    /*if(text_input[strlen(text_input) - 1] != '\n')
    {
        printf("Input line too long.\n");
        read_rest_of_line();
    }
    else
    {
        text_input[strlen(text_input) - 1] = '\0';
        check = TRUE;
    }*/
    while(fgets(text_input, 2, stdin))
    {
        if(strcmp(text_input, play) == 0)
        {
            printf("Continue...\n");
        }
        else if(strcmp(text_input, quit) == 0)
        {
            printf("Quitting...\n");
            return 0;
        }
        else
        {
            printf("Invalid input.\n");
        }
    }
    return EXIT_SUCCESS;
}

/*void read_rest_of_line() 
{
    int ch;
    while(ch=getchar(), ch != '\n' && ch != EOF)
    {
        clearerr(stdin);
    }
}*/
