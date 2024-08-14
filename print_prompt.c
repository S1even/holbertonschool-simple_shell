#include "shell.h"

/**
 * print_prompt - function to print a custom prompt
 * Return: nothing
 */

void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("♠ ");
		fflush(stdout);
	}
}
