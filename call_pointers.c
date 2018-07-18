#include <stdio.h>
#include <stdlib.h>

/* Function prototype for swapping integers*/
void swap(int *a, int *b);

int main(void)
{
    int x = 20, y = 10;
    swap(&x, &y); /* call to function swap - to each addresses of int pointers*/ 
    printf("%d %d\n", x, y); /*Swapped values*/
    return EXIT_SUCCESS;
}

/* function swap()*/
/* 2 int pointer variables */
void swap(int *a, int *b)
{
    /* For this example, a will contain the address of FIRSTNUM, and
    b will contain the address of SECONDNUM */
    int temp;
    temp = *a; /* Dereferencing operator * used to assign FIRSTNUM value (10) to temp */
    *a = *b; /* FIRSTNUM is assigned to SECONDNUM (20)*/
    *b = temp; /* SECONDNUM is assigned to temp which has (10) from FIRSTNUM*/
}
