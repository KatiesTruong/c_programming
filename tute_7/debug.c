#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    int *intArray;
    char string[50];
    for (i = 0; i <= 10; i++) {
        intArray[i] = rand() % 10;
    }
    printf("''string'' is %i characters long\n", strlen(string));
    strcpy(string, "This is a medium sized string");
    printf("''string'' is %i characters long\n", strlen(string));
    return EXIT_SUCCESS;
}
