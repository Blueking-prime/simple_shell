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
* @command: command to be executed
*
* @parent: Name of shell
*
* @env: Process environment
*
* @counter: No of programs executing so far
*
* Return: input string.
*/
void execute_command(char **command, char *parent, char **env, int counter)
{
	int exec_ret, i = 0, ct = counter;
	char *newargv[] = {NULL, NULL};

	while (command[i])
	{
		newargv[i] = command[i];
		i++;
	}
	newargv[i] = NULL;

	exec_ret = execve(newargv[0], newargv, env);
	if (exec_ret == -1)
	{
		if (newargv[1] == NULL)
		{
			fprintf(stderr, "%s: %d: %s: %s\n", parent, ct, newargv[0], strerror(errno));
			exit(errno);
		}
		else
		{
			fprintf(stderr, "%s: %s: %s\n", newargv[0], newargv[1], strerror(errno));
			exit(errno);
		}
	}

	for (i = 0; newargv[i] != NULL; i++)
	{
		free(newargv[i]);
	}

}

/**
* fork_and_exec - Executes the users command
*
* @command: command to be executed
*
* @parent: Name of shell
*
* @env: Process environment
*
* @counter: No of programs executing so far
*
* Return: Nothing.
*/
void fork_and_exec(char **command, char *parent, char **env, int counter)
{
	pid_t c_pid;
	int status;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror(strerror(errno));
		exit(errno);
	}

	if (c_pid == 0)
	{
		execute_command(command, parent, env, counter);
	}
	else
	{
		wait(&status);
	}
}

/**
* arg_split - Parses the users input
*
* @input: input string
*
* Return: List of arguments
*/
char **arg_split(char *input)
{
	char **arg_list;
	int i, j = 0;
	char *token;

	for (i = 0; input[i] != '\0'; i++)
		;
	i++;

	arg_list = malloc((i * sizeof(char)) + sizeof(NULL) + (7 * sizeof(char)));
	if (arg_list == NULL)
	{
		free(arg_list);
		exit(errno);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		arg_list[j] = token;
		token = strtok(NULL, " ");
		j++;
	}

	return (arg_list);
}
