#include "main.h"

/**
* input_prompt - Requests user input
*
* Return: input string.
*/
char *input_prompt(void)
{
	size_t input_size;
	int stat;
	char *input = NULL;


	if (isatty(STDIN_FILENO) == 1)
	{
		printf("($) ");
	}
	stat = getline(&input, &input_size, stdin);
	if (stat == -1)
	{
		free(input);
		if (isatty(STDIN_FILENO) == 1)
		{
			putchar('\n');
		}
		exit(0);
	}

	return (input);
	free(input);
}

/**
* check_if_exit - checks if exit was triggered
*
* @command: The users input string
*
* Return: 1 or 0.
*/
int check_if_exit(char *command)
{
	int i;
	char *exit_command = "exit";

	for (i = 0; exit_command[i] != '\0'; i++)
	{
		if (command[i] != exit_command[i])
		{
			break;
		}
	}

	if (i < 4)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* check_if_env - checks if env was requested
*
* @command: The users input string
*
* @env: The users environment
*
* Return: 1 or 0.
*/
int check_if_env(char *command, char **env)
{
	int i;
	char *environment_command = "env";

	for (i = 0; environment_command[i] != '\0'; i++)
	{
		if (command[i] != environment_command[i])
		{
			break;
		}
	}

	if (i < 3)
	{
		return (1);
	}
	else
	{
		_printenv(env);
		return (0);
	}
}

/**
* format_input - removes newline character from input
*
* @command: The users input string
*
* Return: input string.
*/
char *format_input(char *command)
{
	int i;

	for (i = 1; command[i] != '\0'; i++)
	{
		if (command[i] == '\n')
		{
			command[i] = command[i+1];
		}
	}

	return (command);
}