#include <stdio.h>
#include <stdlib.h>
#define LIMITRANGE 10
/* Functional programming method towards Fibonnaci idea*/

int makeFibonnaci(num)
{
    int lastNum = -1;
    if(num <= lastNum) {
        return EXIT_FAILURE;
    } else if(num == 0) {
        return 0;
    } else {
        return(num +(makeFibonnaci(num - 1)));
    }
}

int main(void) 
{
    printf("%d\n", makeFibonnaci(LIMITRANGE));
    return EXIT_SUCCESS;
}


