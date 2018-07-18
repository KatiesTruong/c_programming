#include <stdio.h>
#include <stdlib.h>

void doit()
{
}

int main(void)
{
    int ch;
    doit();
    while(ch = getchar(), ch!= '\n' && ch!= EOF)
    {
        putchar(ch);
    }
    return EXIT_SUCCESS;
}
