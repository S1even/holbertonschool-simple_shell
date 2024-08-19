#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


void print_prompt(void);
ssize_t read_command(char **buffer, size_t *size);
char **parse_command(char *command);
void execute_command(char **parsed_command, char *program_name, char **env);
void exit_shell(void);
void env_variables(char **env);
int check_path_executable(const char *path);
char *create_command_path(char *command);
void execute_in_child(char *cmd_path, char **parsed_command, char **env);
char *find_command_in_path(char *command);

#endif
