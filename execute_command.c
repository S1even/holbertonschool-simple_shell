#include "shell.h"

/**
 * execute_command - execute the command
 * @argv: array of arguments (program + arguments)
 */

void execute_command(char **argv)
{
	struct stat st;

	if (stat(argv[0], &st) == 0 && (st.st_mode & S_IXUSR))
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
		}
	}
	else
	{
		perror("./shell");
	}
	free(argv);
}
