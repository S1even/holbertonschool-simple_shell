#include "shell.h"

/**
 * execute_command - execute the command
 * @command: command to be executed
 */

void execute_command(char *command)
{
	char *argv[2];
	struct stat st;

	argv[0] = command;
	argv[1] = NULL;

	if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("./shell");
		}
	}
	else
	{
		perror("./shell");
	}
}
