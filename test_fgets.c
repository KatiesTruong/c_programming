#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define SIZE 5
#define EXTRACHARS 2

typedef enum 
{
    FALSE,
    TRUE
} BOOLEAN;

/* Prototype */
void readRestOfLine();

int main(void)
{
    char myString[SIZE + EXTRACHARS];
    int finished = FALSE;
    int i;

    /* Continue to accept input from the user until a string of
    no greater than SIZE characters is entered. */
    do
    {
        /* User prompt */
        printf("Enter some text(1 -5 characters): ");

        /* Accept a line of text.
        We use +2 here for the trailing \n and \0 
        */
        fgets(myString, SIZE + 2, stdin);

        /* Is there a '\n' character in the string? 
        Because if there is, we want to get rid of it. 
        fgets() leaves the '\n' character in the string 
        unless there isn't enough room to store it.*/
        /* Checks the end of the character whether it is
        \n or not. If it isn't then it rejects it with the
        readRestOfLine() function */
        if(myString[strlen(myString) - 1] != '\n')
        {
            printf("Input was too long.\n");
            readRestOfLine();
        } 
        else
        {
            /* String length is good, Remove the '\n'
            character */
            myString[strlen(myString) - 1] = '\0';
            finished = TRUE;
        }
    } while(!finished); /* while finished it false */
    /* The remainder of this program just displays diagonistic
    information. This can be helpful when debugging. This information
    outputs the string, each character in the array,
    and the length of the string. */
    printf("Debugging Information:\n");

    printf("You entered: '%s'\n", myString);

    for(i = 0; i < SIZE + 2; i++)
    {
        if(myString[i] == '\n')
        {
            printf("myString: '\\n' found at array index %d\n", i);
        }
        else if(myString[i] == '\0')
        {
            printf("myString: '\\0' found at array index %d\n", i);
        }
        else if(myString[i] == '\r')
        {
            printf("myString: '\\r' found at array index %d\n", i);
        }
        else
        {
            printf("myString: '%c' found at array index %d\n", myString[i], i);
        }
    }
    printf("Length of string: %lu characters\n\n", strlen(myString));
    return EXIT_SUCCESS;
}


/* readRestOfLine() function: reads the remaining characters in the standard
input buffer up to the next newline of EOF */

void readRestOfLine()
{
    int c;
    /* read until the end of line or EOF */
    while((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        /* clear the error and EOF flags*/
        clearerr(stdin);
    }
}
