#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUTLEN 3
#define EXTRACHARS 2

typedef enum {
    FALSE,
    TRUE
} BOOLEAN;

int main(void)
{
    char tok_prompt[INPUTLEN+EXTRACHARS];
    char *token;
    int nums;
    int limit_nums = 0;
    char* end;
    BOOLEAN error = FALSE;

    printf("Please enter the location for a token: ");
    fgets(tok_prompt, INPUTLEN+EXTRACHARS, stdin);

    token = strtok(tok_prompt, ",");
    while(token != NULL)
    {
        limit_nums= (int) strtol(tok_prompt,&end, 0 );
        if(limit_nums <=15 && limit_nums >= 0)
        {
            nums = limit_nums;
        } 
        else 
        {
            if(*end!=0) 
            {
                printf("Error! Must be a number\n");
                return error;
            }
            else if(limit_nums == 0) 
            {   
                printf("Error! Must be center!\n");
                return error;
            }
        }
        printf("%d\n", nums);
        token = strtok(NULL, ",");
    }
    return EXIT_SUCCESS;
}
