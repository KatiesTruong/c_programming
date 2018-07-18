#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    /* While the user has not pressed ctrl+d, keep on receiving characters
    note that the input is not processed until the enter key has been pressed.
    Reads character from keyboard until it is at the end of a file and new line or ctl+d*/
    while (ch=getchar(), ch != '\n' && ch!= EOF)
    {
        putchar(ch);
    }
    return EXIT_SUCCESS;
}
