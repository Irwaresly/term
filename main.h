#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

char *getUserInput();
void displayPrompt();
char **parseInput(char *input);
int executeExternalCommand(char **tokens);
int handleBuiltInCommand(char **tokens);

#endif
