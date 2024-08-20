#include "shell.h"

/**
 * find_executable - searches for the executable in the directories in PATH
 * @command: the name of the command to search for
 * Return: full path of the executable if found, otherwise NULL
 */

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *dir;
	char *full_path = NULL;
	struct stat st;

	if (!path)
		return (NULL);
	dir = strtok(path, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			perror("malloc");
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IFREG))
			return (full_path);
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * handle_child_process - handles the execution of the command in the process
 * @argum: array of arguments for the command to execute
 * @commandLine: the original command line input
 * @argv: the name of the program (used in error messages)
 */
void handle_child_process(char **argum, char *commandLine, char *argv)
{
	char *full_path = find_executable(argum[0]);


	if (full_path)
	{
		execve(full_path, argum, environ);
		perror("execve");
		free(full_path);
		exit(1);
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv, argum[0]);
		free(commandLine);
		free_argument(argum);
		exit(127);
	}
}

/**
 * execute_command - executes a command in a child process
 * @status: pointer to an integer that will hold the status of the process
 * @pid: process ID returned by fork()
 * @argum: array of arguments for the command to execute
 * @commandLine: the original command line input
 * @exit_status: pointer to an integer to store the exit status of the command
 * @argv: the name of the program (used in error messages)
 */
void execute_command(int *status, pid_t pid, char **argum, char *commandLine,
		int *exit_status, char *argv)
{
	if (pid == 0)
	{
		handle_child_process(argum, commandLine, argv);
	}
	else
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status))
			*exit_status = WEXITSTATUS(*status);

		free_argument(argum);

		if (*exit_status != 0)
		{
			free(commandLine);
			exit(127);
		}
	}
}
