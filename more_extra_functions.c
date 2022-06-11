#include "main.h"

/**
* _printenv - prints the environment
*
* @env: environment variable
*
* Return: Always 0.
*/
void _printenv(char **env)
{
	unsigned int i;

    i = 0;
    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }
}

/**
* execute_command - Executes the users command
*
* Return: input string.
*/
void execute_command(char *command, char *parent, char **env, int counter)
{
	int exec_ret, i;
	char *newargv[] = {NULL, NULL};

	newargv[0] = command;
	exec_ret = execve(newargv[0], newargv, env);
	if (exec_ret == -1)
	{
		if (newargv[1] == NULL)
		{
			fprintf(stderr,"%s: %d: %s: %s\n", parent, counter, newargv[0], strerror(errno));
			exit(errno);
		}
		else
		{
			fprintf(stderr,"%s: %s: %s\n", newargv[0], newargv[1], strerror(errno));
			exit(errno);
		}
	}

	for (i = 0; newargv[i] != NULL; i++)
	{
		free(newargv[i]);
	}

}

/**
* check_path - prints the environment
*
* @command: input command
*
* Return: location of file
*/
/**char *check_path(char *command)
{
	int i = 0;
	char *buffer;
	char *split_path[] = {NULL, NULL};
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	split_path[i] = token;
	i++;

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		split_path[i] = token;
		i++;
	}

	buffer = split_path[i] + '/' + command;
	if (access(buffer, X_OK))
	{
		return (buffer);
	}
	return (command);
}*/