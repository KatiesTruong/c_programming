/* Pre-processor directives */
#include <stdio.h>
#include <stdlib.h>

/* Function heading and start of block */
int main(void)
{
    /* Variable Declarations */
    int ass1, ass2, exam;
    float total;

    /* Prompts user*/
    printf("Please add in 3 integers for Assignment 1, Assignment 2 and Exam marks: \n");
    /* data input */
    if (scanf("%d%d%d", &ass1, &ass2, &exam) != 3)
    {
        printf("Unable to find 3 integers on standard input\n");
        return EXIT_FAILURE;
    }
    /* Arithmetic expressions and assignment */
    total = ass1 * 0.2 + ass2 * 0.3 + exam * 0.5;

    /* Output */
    printf("Here are your mark results:\n");
    printf("Assignment 1 = %3d\n", ass1);
    printf("Assignment 2 = %3d\n", ass2);
    printf("Exam = %3d\n", exam);
    printf("Total = %6.2f\n", total);

    /* Terminate Program */
    return EXIT_SUCCESS;
}


