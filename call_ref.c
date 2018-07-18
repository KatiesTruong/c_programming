#include <stdio.h>
#include <stdlib.h>
#define FIRSTNUM 10
#define SECONDNUM 4

/* Place prototype function here */
void swap(int a, int b);

int main(void)
{
    swap(FIRSTNUM, SECONDNUM);
    printf("%d %d\n", FIRSTNUM, SECONDNUM);
    return EXIT_SUCCESS;
}

/* function swap()*/
/* a and b are formal parameters */
void swap(int a, int b)
{
    /* For this example a and b created and initialised. a and b 
    behave like local variables and are only copies of FIRSTNUM and SECONDNUM*/
    int temp; /* local variable initially undefined */
    temp = a; /* Assign a value (10) to temp*/
    a = b; /* Assign a to (4)*/
    b = temp; /* Assign b to (10)*/
    /* none of this is passed because the copies of FIRSTNUM
    & SECONDNUM are passed instead of their addresses. For pointers this is
    important.
    */
}
