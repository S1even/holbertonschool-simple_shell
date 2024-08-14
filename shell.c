#include "shell.h"

/**
 * main - entry point of the simple shell program
 * Return: always 0 on success
 */

int main(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t read;
	char **argv;

	while (1)
	{
		print_prompt();
		read = read_command(&command, &size);

		if (read == -1)
		{
			free(command);
			exit(0);
		}

		if (strcmp(command, "") == 0)
			continue;

		argv = parse_command(command);
		if (!argv)
		{
			free(command);
			exit(1);
		}
		if (fork() == 0)
		{
			execute_command(argv);
			free(argv);
			_exit(1);
		}
		else
		{
			wait(NULL);
			free(argv);
		}
	}

	free(command);
	return (0);
}
