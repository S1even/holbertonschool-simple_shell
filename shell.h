#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>

#define MAX_CHARS 1024
extern char environ;


char token_path(char path, char delim, char filename);
char **token_line(char *command_line, const char *delim);
char command_path(char cmd);
void free_argument(char **argum);
void print_prompt(void);
void execute_command(int *status, pid_t pid, char **argum, char *commandLine,
		int *exit_status, char *argv);

#endif
