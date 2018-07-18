#include <stdio.h>
#include <stdlib.h>
#define FIRSTNUM 10
#define SECONDNUM 20

int sum(int a, int b); /* Prototype required for ANSI C, it is used before main() */

int main(void)
{
    int result;
    result = sum(FIRSTNUM, SECONDNUM);

    printf("%d + %d = %d\n", FIRSTNUM, SECONDNUM , result);
    return EXIT_SUCCESS;
}

/* Declaration of function sum(...) */
int sum(int a, int b)
{
    return (a + b);
}
