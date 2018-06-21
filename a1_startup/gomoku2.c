#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUTLIMIT 1
#define EXTRACHARS 2
#define BOARDHEIGHT 10
#define BOARDWIDTH 10
typedef enum { FALSE, TRUE } BOOLEAN;

/* Prototype function */

void read_rest_of_line();

void print_board(int board[BOARDHEIGHT][BOARDWIDTH]);

int main(void) {
    int check = FALSE;
    char text_input[INPUTLIMIT + EXTRACHARS];
    char *play = "1";
    char *quit = "2";
    int board[BOARDHEIGHT][BOARDWIDTH] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    /* Menu prompts user */
    do {
        printf("Welcome to Gomoku\n");
        printf("================\n");
        printf("1) Play the game\n");
        printf("2) Quit the game\n");
        fgets(text_input, INPUTLIMIT + EXTRACHARS, stdin);
        if (strcmp(text_input, quit) == 0) {
            printf("Quitting...");
            return 0;
        }
        if (text_input[strlen(text_input) - 1] != '\n') {
            printf("Input was too long.\n");
            read_rest_of_line();
        } else {
            text_input[strlen(text_input) - 1] = '\0';
            check = TRUE;
        }
    } while (!check && strcmp(text_input, play));
    print_board(board);
    return EXIT_SUCCESS;
}

/* Boolean function that tests whether user
quits the menu */
/* Fix up menu input validation to make '1' proceed
but '2' to stop*/
/* Fix board print, may separate each board height and width
then combine in another function or find a way within the same
for loop.  Set (int board[BOARDHEIGHT][], int board[][BOARDWIDTH])
as parameters? */
/*
void print_board(int board[BOARDHEIGHT][BOARDWIDTH]) {
    int row;
    int y_axis, x_axis;
    char *tokens = " ";
    for (row = 0; row < 1; row++) {
        "  |"
        printf("  |");
        for (x_axis = 1; x_axis <= 15; x_axis++) {
            if (x_axis > 9) {
                printf("%d |", x_axis);
            } else if (x_axis < 9) {
                printf(" %d |", x_axis);
            }
        }
        printf("\n");
        for (y_axis = 15; y_axis >= 1; y_axis -= 1) {
            if (y_axis < 9) {
                printf(
                    "----------------------------------------------------------"
                    "-\n");
                printf(
                    "%d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens);
            } else if (y_axis > 9) {
                printf(
                    "----------------------------------------------------------"
                    "-\n");
                printf(
                    "%d| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s | %s | %s |\n",
                    y_axis, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens);
            }
        }
        printf("\n");
    }
}
*/

void print_board(int board[BOARDHEIGHT][BOARDWIDTH]) {
    int row;
    int y_axis, x_axis;
    char tokens[] = " ";
    for (row = 0; row < 1; row++) {
        printf("  |");
        for (x_axis = 1; x_axis <= 15; x_axis++) {
            if (x_axis > 9) {
                printf("%d |", x_axis);
            } else if (x_axis < 9) {
                printf(" %d |", x_axis);
            }
        }
        printf("\n");
    }
    for (row = 0; row < 1; row++) {
        for (y_axis = 15; y_axis >= 1; y_axis -= 1) {
            if (y_axis < 9) {
                printf(
                    "------------------------------------------------------"
                    "----"
                    "-\n");
                printf(
                    "%d | %s | %s | %s | %s | %s | %s | %s | %s | %s | %s "
                    "| %s "
                    "| %s | %s | %s |\n",
                    y_axis, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens);
            } else if (y_axis > 9) {
                printf(
                    "------------------------------------------------------"
                    "----"
                    "-\n");
                printf(
                    "%d| %s | %s | %s | %s | %s | %s | %s | %s | %s | %s | "
                    "%s "
                    "| %s | %s | %s |\n",
                    y_axis, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens, tokens, tokens, tokens, tokens, tokens, tokens,
                    tokens);
            }
        }
    }
    printf("\n");
}

void read_rest_of_line() {
    int ch;
    while (ch = getchar(), ch != '\n' && ch != EOF) {
        clearerr(stdin);
    }
}
