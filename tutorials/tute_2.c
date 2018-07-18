#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int miles, yards;
    double kilometres;
    yards = 26;
    miles = 385;
    kilometres = 1.609 * (miles + yards/1760);
    printf("%d miles, %d yards = %f kilometres\n", miles, yards, kilometres);
    return EXIT_SUCCESS;
}
