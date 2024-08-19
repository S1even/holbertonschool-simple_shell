#include "shell.h"

/**
 * read_command - reads a command from the user
 * @buffer: pointer to the buffer where the command will be stored
 * @size: pointer to the size of the buffer
 * Return: number of characters read, or -1 on failure
 */

ssize_t read_command(char **buffer, size_t *size)
{
	ssize_t read_bytes, i;
	size_t buffer_size = 1024;

	if (*buffer == NULL)
	{
		*buffer = malloc(buffer_size);
		if (*buffer == NULL)
			return (-1);
		*size = buffer_size;
	}

	read_bytes = read(STDIN_FILENO, *buffer, buffer_size - 1);
	if (read_bytes < 0)
	{
		free(*buffer);
		return (-1);
	}

	(*buffer)[read_bytes] = '\0';
	for (i = 0; i < read_bytes; i++)
	{
		if ((*buffer)[i] == '\n')
		{
			(*buffer)[i] = '\0';
			break;
		}
	}

	if (read_bytes == 0 || (*buffer)[0] == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		*size = 0;
		return (0);
	}

	return (read_bytes);
}
