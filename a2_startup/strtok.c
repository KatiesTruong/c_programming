#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS ","
#define BUFF_SIZE 1020
int main(int argc, char** argv) {
    FILE* tile_file;
    char* token;
    char buffer[BUFF_SIZE];
    char* tile_name = "tiles.txt";

    tile_file = fopen("tiles.txt", "r");

    if (tile_file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", tile_name);

    } else {
        while (fgets(buffer, BUFF_SIZE, tile_file) != NULL) {
            token = strtok(buffer, DELIMS);
            while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, DELIMS);
            }
        }

        if (ferror(tile_file)) {
            perror("The following error occurred");
        }

        fclose(tile_file);
    }
    return EXIT_SUCCESS;
}
