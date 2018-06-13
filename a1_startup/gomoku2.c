#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define INPUTLIMIT 1
#define EXTRACHARS 2
#define BOARDHEIGHT 10
#define BOARDWIDTH 10
typedef enum 
{
    FALSE,
    TRUE
} BOOLEAN;

/* Protodype function */
int menu();

void readRestOfLine();

void print_board(int board[BOARDHEIGHT][BOARDWIDTH]);

int main(void)
{
    char textInput[INPUTLIMIT+EXTRACHARS];
    int board[BOARDHEIGHT][BOARDWIDTH]={
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
    };
    /* Menu prompts user */
    do
    {
        printf("Welcome to Gomoku\n");
        printf("================\n");
        printf("1) Play the game\n");
        printf("2) Quit the game\n");
        fgets(textInput, INPUTLIMIT + EXTRACHARS, stdin);
        readRestOfLine();
    } while(!menu);
    print_board(board);
    return EXIT_SUCCESS;
}

/* Boolean function that tests whether user
quits the menu */
/* Fix up menu input validation to make '1' proceed 
but '2' to stop*/
int menu()
{
    char input_char;
    if(input_char == '1')
    {
        printf("Going to menu...");
        return TRUE;
    } 
    else if(input_char == '2')
    {
        printf("Quitting...");
        return FALSE;
    } 
    else
    {
        printf("Invalid input.");
    }
    return EXIT_SUCCESS;
}

/* Fix board print, may separate each board height and width
then combine in another function or find a way within the same
for loop.  Set (int board[BOARDHEIGHT][], int board[][BOARDWIDTH])
as parameters? */
void print_board(int board[BOARDHEIGHT][BOARDWIDTH])
{
    signed y_axis, x_axis;
    for(y_axis = 0; y_axis < 10; y_axis++)
    {
        printf("%d -", board[y_axis][x_axis]);
        for(x_axis = 0; x_axis < 10; x_axis++)
        {
            printf("%d |", board[y_axis][x_axis]);
        }
    }
}

void readRestOfLine()
{
    int ch;
    while(ch=getchar(), ch != '\n' && ch!=EOF)
    {
        clearerr(stdin);
    }
}
