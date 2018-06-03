#include <stdio.h>
#include <stdlib.h>

typedef enum options
{
    /* numbered in indices of 0,1,2,3,4. case FOURTH and FIFTH are set as the same for this very reason.*/
    FIRST, SECOND, THIRD, FOURTH, FIFTH
} options;

int main(void)
{
    options opt = 4;
    switch(opt)
    {
        case FIRST:
            printf("%d\n", 1);
            break;
        case SECOND:
            printf("%d\n", 2);
            break;
        case THIRD:
            printf("%d\n", 3);
            break;
        case FOURTH:
        case FIFTH:
            printf("%d\n", 4);
            break;
        default:
            printf("invalid value: %d\n", opt);
    }
    return EXIT_SUCCESS;
}
