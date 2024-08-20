#include "shell.h"

/**
 * execute_command - executes a command in a child process
 * @status: pointer to an integer that will hold the status of the child proces
 * @pid: process ID returned by fork()
 * @argum: array of arguments for the command execute
 * @commandLine: the original command line input
 * @exit_status: pointer to an integer to store the exit status of the command
 * @argv: the name of the program(used in error messages)
 */
void execute_command(int *status, pid_t pid, char **argum, char *commandLine,
		int *exit_status, char *argv)
{
	if (pid == 0)
	{
		if (execvp(argum[0], argum) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv, argum[0]);
			free(commandLine);
			free_argument(argum);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status))
		{
			*exit_status = WEXITSTATUS(*status);
		}
		free_argument(argum);
		if (*exit_status != 0)
		{
			free(commandLine);
			exit(127);
		}
		return;
	}
}
