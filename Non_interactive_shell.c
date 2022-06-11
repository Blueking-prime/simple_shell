#include "main.h"

/**
* non_interactive_mode - Run the shell in non_interactive mode
*
* @argc: No of arguments
*
* @argv: Array of arguments
*
* @env: Process environment
*
* Return: (Always/Success)
*/

int non_interactive_mode(int argc, char **argv, char **env)
{
	int i, j, exec_ret;
	char *newargv[1024];

	for (i = 0, j = 1; j < argc; i++, j++)
	{
		newargv[i] = argv[j];
	}

	exec_ret = execve(newargv[0], newargv, env);
	if (exec_ret == -1)
	{
		fprintf(stderr,"%s: 1: %s: %s\n", argv[0], newargv[1], strerror(errno));
		exit (127);
	}

	return (0);
}
