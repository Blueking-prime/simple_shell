#include "main.h"

/**
* interactive_mode - Runs the shell in interactive mode
*
* @parent: The shell
*
* @env: The users environment
*
* Return: (Always/Success)
*/

int interactive_mode(char *parent, char **env)
{
	pid_t c_pid;
	int status, counter = 1;
	char *command = NULL, *input = NULL;

	while (1)
	{
		input = input_prompt();
		command = format_input(input);
		/*Builtin checks*/
		if (command[0] == '\n')
		{
			free(command);
			continue;
		}

		if (check_if_exit(command) == 0)
			break;

		if (check_if_env(command, env) == 0)
		{
			counter++;
			continue;
		}
		/*Create child process*/
		c_pid = fork();
		if (c_pid == -1)
		{
			perror(strerror(errno));
			exit(errno);
		}

		if (c_pid == 0)
			execute_command(command, parent, env, counter);
		else
			wait(&status);

		free(command);
		counter++;
	}
	return (0);
}
