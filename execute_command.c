#include "shell.h"

/**
 * execute_command - execute the command
 * @argv: array of arguments (program + arguments)
 */

void execute_command(char **argv)
{
	char *cmd_path = NULL;
	struct stat st;

	if (stat(argv[0], &st) == 0 && (st.st_mode & S_IXUSR))
		cmd_path = argv[0];
	else
	{
		cmd_path = find_command_in_path(argv[0]);
		if (!cmd_path)
		{
			perror("./shell");
			free(argv);
			return;
		}
	}
	if (execve(cmd_path, argv, NULL) == -1)
		perror("./shell");
	if (cmd_path != argv[0])
		free(cmd_path);
	free(argv);
}
