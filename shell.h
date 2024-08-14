#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void);
void print_prompt(void);
void read_command(char *buffer);
void execute_command(char *command);

#endif
