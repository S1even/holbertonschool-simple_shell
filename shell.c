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

		if (fork() == 0)
		{
			execute_command(command);
			_exit(1);
		}

		else
			wait(NULL);
	}

	free(command);
	return (0);
}
