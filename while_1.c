#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int i = 1; /* Initialising i */
   while (i++ <= 10 )
      printf("%d\n", i);

/* After the first while loop i
   now equals 11 - is this correct ? */

   while (i--)
      printf("%d\n", i);

/* i now equals ? */
    return EXIT_SUCCESS;
}
