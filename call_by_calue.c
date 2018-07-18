#include <stdio.h>
#include <stdlib.h>
#define FIRSTNUM 10
#define SECONDNUM 40
/* Function display prototype, in a larger file this should go in a separate header file */
void display(int a, int b);

int main(void)
{
    /* FIRSTNUM and SECONDNUM are called arguments or actual parameters */
    display(FIRSTNUM, SECONDNUM); /* function call that has no return value */
    return EXIT_SUCCESS; /* main() returns an int */
}

/* Usually place functions after main()*/

/* a and b are called 'formal parameters'*/
void display(int a, int b)
{
    printf("First = %d\n", a);
    printf("Second = %d\n", b);
} /* End of function display()*/
