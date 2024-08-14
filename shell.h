#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(void);
void print_prompt(void);
ssize_t read_command(char **buffer, size_t *size);
void execute_command(char *command);

#endif
