#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(size_t));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));

    return EXIT_SUCCESS;
}
