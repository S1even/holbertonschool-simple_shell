#include "shell.h"

/**
 * main - Entry point of the simple shell program
 * @argv: Argument vector
 * @envp: Environment variables
 * Return: Always 0 on success
 */

int main(char **argv, char **envp)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t nread;

	while (1)
	{
		print_prompt();
		nread = read_command(&command, &size);

		if (nread == -1 || handle_empty_command(command))
		{
			free(command);
			exit(0);
		}

		handle_command(command, envp);
	}

	free(command);
	return (0);
}

/**
 * handle_empty_command - Handles empty commands
 * @command: The command entered by the user
 * Return: 1 if the command is empty, 0 otherwise
 */

int handle_empty_command(char *command)
{
	if (strcmp(command, "") == 0)
		return (1);
	return (0);
}

/**
 * handle_command - Handles the execution of a command
 * @command: The command entered by the user
 * @envp: The environment variables
 */

void handle_command(char *command, char **envp)
{
	char **argv;

	argv = parse_command(command);
	if (!argv)
	{
		free(command);
		exit(1);
	}

	if (execute_builtin_commands(argv, envp))
	{
		free(argv);
		return;
	}

	execute_non_builtin_command(argv);
	free(argv);
}

/**
 * execute_builtin_commands - Executes built-in commands like exit and env
 * @argv: The array of arguments (command and arguments)
 * @envp: The environment variables
 * Return: 1 if a built-in command was executed, 0 otherwise
 */

int execute_builtin_commands(char **argv, char **envp)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit_shell();
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		env_variables(envp);
		return (1);
	}

	return (1);
}

/**
 * execute_non_builtin_command - Executes commands that are not built-in
 * @argv: The array of arguments (command and arguments)
 */

void execute_non_builtin_command(char **argv)
{
	if (fork() == 0)
	{
		execute_command(argv);
		_exit(1);
	}
	else
		wait(NULL);
}
