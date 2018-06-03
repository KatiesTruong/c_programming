#include <stdio.h>
#include <stdlib.h>

typedef enum options
{
    FIRST, SECOND, THIRD, FOURTH, FIFTH
} options;   

int main(void)
{
    options opt = 3;
    printf("%d\n", opt + 1);
    switch(opt)
    {
        case FIRST:
            printf("%d\n", opt + 1);
            break;
        case SECOND:
            printf("%d\n", opt + 1);
            break;
        case THIRD:
            printf("%d\n", opt + 1);
            break;
        case FOURTH:
            printf("%d\n", opt + 1);
            break;
        case FIFTH:
            printf("%d\n", opt + 1);
            break;
    }
    return EXIT_SUCCESS;
}
