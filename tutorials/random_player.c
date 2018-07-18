#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2

int main(void) {
    int random_player;
    srand(time(NULL));
    random_player = rand() % NUM_PLAYERS;
    printf("%d\n", random_player);
    return EXIT_SUCCESS;
}
