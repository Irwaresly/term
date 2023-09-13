#include "main.h"

int main(int ac, char **argv)
{

    char *input = NULL;
    char **tokens = NULL;
    int i;

    /* declaring void variables */
    (void)ac;
    (void)argv;

    while (1)
    {
        displayPrompt();

        input = getUserInput();

        if (input == NULL)
        {
            perror("getline");
            exit(1);
        }

        tokens = parseInput(input);

        
        if (handleBuiltInCommand(tokens) == -1) {
            executeExternalCommand(tokens);
        }


        /* Freeing Memory */
        for (i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);

        printf("%s\n", input);

        free(input);
    }

    return (0);
}