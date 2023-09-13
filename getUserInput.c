#include "main.h"

char *getUserInput()
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t read_result;

    read_result = getline(&lineptr, &n, stdin);

    if (read_result == -1)
    {
        if (feof(stdin))
        {
            printf("Goodbye!\n");
            exit(0);
        }
        else
        {
            perror("Error in getUserInput: getline failed");
            exit(1);
        }
    }

    return lineptr;
}
