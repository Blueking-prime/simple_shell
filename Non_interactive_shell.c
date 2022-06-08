#include "main.h"

/**
* main - Entry Point
*
* Return: (Always/Success)
*/

int main(int argc, char **argv)
{
	int exec_ret;
	char *newargv[] = {NULL, NULL};

	if (argc > 1)
	{
		newargv[0] = argv[1];
		exec_ret = execve(newargv[0], newargv, NULL);
		if (exec_ret == -1)
		{
			perror("Error: command did not execute");
			return (1);
		}
	}
	else
	{
		printf("This is where I'd run the interactive shell, but I'll do that tomorrow\n");
	}

	return (0);
}
