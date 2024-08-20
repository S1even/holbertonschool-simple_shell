#include "shell.h"

/**
 * main - entry point of the shell program
 * @argc: argument count (not use in this program)
 * @argv: agrument vector, where argv[0] is the program name
 * Return: exit status of the last executed command, or 0 if successful
 */

int main(int argc, char **argv)
{
	pid_t pid;
	char *commandLine = NULL, *delim = " \n", **argum = NULL;
	int status = 0, exit_status = 0, chars = 0;
	size_t max = MAX_CHARS;
	(void) argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_prompt();
	chars = getline(&commandLine, &max, stdin);
		if (strcmp(commandLine, "\n") == 0)
			continue;
		if (strcmp(commandLine, "exit\n") == 0)
		{
			free(commandLine);
			return (exit_status);
		}
		if (chars == -1)
		{
			free(commandLine);
			exit(0);
		}
		argum = token_line(commandLine, delim);
		if (argum == NULL)
			continue;

		pid = fork();
		execute_command(&status, pid, argum, commandLine, &exit_status, argv[0]);
	}
	exit(0);
}
