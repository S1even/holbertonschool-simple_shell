#include "shell.h"

/**
 * free_argument - frees memory allocated for an array on strings
 * @argum: array of strings to be freed
 */

void free_argument(char **argum)
{
	int i = 0;

	while (argum[i])
	{
		free(argum[i]);
		i++;
	}
	free(argum);
}
