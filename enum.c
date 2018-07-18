#include <stdio.h>
#include <stdlib.h>

enum options
{
    FIRST, SECOND, THIRD, FOURTH, FIFTH
};

char* names[] = {"First", "Second", "Third", "Fourth", "Fifth"};

int main(void)
{
    enum options opt=3;
    printf("%s\n", names[opt]);
    return EXIT_SUCCESS;
}
