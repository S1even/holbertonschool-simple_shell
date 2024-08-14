#include "shell.h"

/**
 * parse_command - Parses the command line into program and arguments
 * @command: The command line input by the user
 * Return: An array of arguments, suitable for execve
 */

char **parse_command(char *command)
{
	int bufsize = 1024, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(command, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 1024;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				return (NULL);
			}
		}

		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}
