#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char options = '1';
    printf("Welcome to Gomoku\n");
    printf("================\n");
    printf("1) Play the game\n");
    printf("2) Quit the game\n");

    if (options == '1')
    {
        printf("Success!\n");
    }
    return EXIT_SUCCESS;
}
