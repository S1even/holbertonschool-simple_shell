#include "shell.h"

/**
 * token_line - tokenizes a command line string into an array of arguments
 * @command_line: the command line string to be tokenized
 * @delim: the delimiters used to split the command line string
 * Return: an array of strings (token) representing the command and arguments,
 * or NULL if no tokens are found
 */

char  **token_line(char *command_line, const char *delim)
{
	char *token = NULL;
	int num_tokens = 0;
	char *command_line_copy = NULL;
	char **argv = NULL;
	int i = 0;

	command_line_copy = malloc(sizeof(char) * strlen(command_line) + 1);
	strcpy(command_line_copy, command_line);
	token = strtok(command_line, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	if (num_tokens == 0)
	{
		free(command_line_copy);
		return (NULL);
	}
	num_tokens++;
	argv = malloc(sizeof(char *) * num_tokens);
	token = strtok(command_line_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	free(command_line_copy);
	argv[i] = NULL;
	return (argv);
}
