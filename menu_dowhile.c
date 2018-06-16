#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define STRING 1
#define EXTRACHARS 2

/* Function prototypes*/

void read_rest_of_line();

typedef enum 
{
    FALSE,
    TRUE
} BOOLEAN;
/* Has double outputs of a printed statement, most likely due to buffer issues.
Will use read_rest_of_line to fix it.*/
/* Add references for: 
    getString-basic.c: https://github.com/muaddib1971/c_examp/blob/master/examples/BasicIO/getString-basic.c
    1   */
int main(void)
{
    int check = FALSE;
    char* play = "1";
    char* quit = "2";
    char text_input[STRING+EXTRACHARS];

    do
    {
        printf("Enter 1 to play, 2 to quit:\n");
        fgets(text_input, STRING+EXTRACHARS, stdin);
        /* Conditional statements for input length and buffering
        for extra new lines*/
        if(text_input[strlen(text_input) - 1] != '\n')
        {
            printf("Input line too long.\n");
            read_rest_of_line();
        }
        else
        {
            text_input[strlen(text_input) - 1] = '\0';
            check = TRUE;
        }
        /* Conditional statements for continuing
        or quitting, will add into a function below*/
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
    } while(!check && strcmp(text_input, play) == 0);
        /*while(fgets(text_input, 2, stdin))*/
        printf("Success!"); 
        return EXIT_SUCCESS;
    }

void read_rest_of_line() 
{
    int ch;
    while(ch=getchar(), ch != '\n' && ch != EOF)
    {
        clearerr(stdin);
    }
}
