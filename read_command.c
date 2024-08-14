#include "shell.h"

/**
 * read_command - reads a command from the user
 * @buffer: pointer to the buffer where the command will be stored
 * @size: pointer to the size of the buffer
 * Return: number of characters read, or -1 on failure
 */

ssize_t read_command(char **buffer, size_t *size)
{
	ssize_t read = getline(buffer, size, stdin);

	if (read != -1)
		(*buffer)[strcspn(*buffer, "\n")] = "\n";

	return (read);
}
