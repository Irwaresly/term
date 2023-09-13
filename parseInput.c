#include "main.h"

#define MAX_TOKENS 100

char **parseInput(char *input)
{

    int i;
    char *token;
    int tokenCount = 0;

    char **tokens = malloc(sizeof(char *) * (MAX_TOKENS + 1));
    if (tokens == NULL)
    {
        perror("malloc");
        exit(1);
    }

    

    for (i = 0; i < MAX_TOKENS; i++)
    {
        tokens[i] = NULL;
    }

    token = strtok(input, " \t\n");

    while (token != NULL && tokenCount < MAX_TOKENS)
    {
        tokens[tokenCount] = strdup(token);
        if (tokens[tokenCount] == NULL)
        {
            perror("strdup");
            exit(1);
        }
        token = strtok(NULL, " \t\n");
        tokenCount++;
    }

    tokens[tokenCount] = NULL;
    return tokens;
}
