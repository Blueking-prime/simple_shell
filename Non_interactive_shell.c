#include "main.h"

/**
* non_interactive_mode - Run the shell in non_interactive mode
*
* @ac: No of arguments
*
* @av: Array of arguments
*
* @env: Process environment
*
* Return: (Always/Success)
*/

int non_interactive_mode(int ac, char **av, char **env)
{
	int i, j;
	int counter = 1, path_check;
	char **command = malloc(sizeof(av) + (7 * sizeof(char)));
	char bin[20];
	char sbin[20];

	for (i = 0, j = 1; j < ac; i++, j++)
	{
		command[i] = av[j];
	}

	if (check_if_exit(av[1]) == 0)
		return (0);

	check_if_env(av[1], env);

	path_check = check_path(command[0]);
	if (path_check == 0)
		command[0] = av[1];

	else if (path_check == 1)
	{
		strcpy(bin, "/bin/");
		command[0] = strcat(bin, av[1]);
	}
	else if (path_check == 2)
	{
		strcpy(sbin, "/sbin/");
		command[0] = strcat(sbin, av[1]);
	}

	fork_and_exec(command, av[0], env, counter);

	return (0);
}
