#include <stdio.h>
#include <stdlib.h>

typedef enum options
{
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
} options;

char* names[] = {"First", "Second", "Third", "Fourth", "Fifth"};

int main(void)
{
    options opt = 3;
    printf("%s\n", names[opt]);
    return EXIT_SUCCESS;
}
