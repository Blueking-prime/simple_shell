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
	int counter = 1, path_check;
	char **command = NULL, *input = NULL, *ppath = NULL;
	char bin[20];
	char sbin[20];

	while (1)
	{
		input = input_prompt();
		ppath = format_input(input);
		if (ppath[0] == '\n')
		{
			free(ppath);
			continue;
		}
		if (check_if_exit(ppath) == 0)
			break;
		if (check_if_env(ppath, env) == 0)
		{
			counter++;
			continue;
		}
		command = arg_split(ppath);
		path_check = check_path(command[0]);
		if (path_check == 0)
			command[0] = ppath;
		else if (path_check == 1)
		{
			strcpy(bin, "/bin/");
			command[0] = strcat(bin, ppath);
		}
		else if (path_check == 2)
		{
			strcpy(sbin, "/sbin/");
			command[0] = strcat(sbin, ppath);
		}
		fork_and_exec(command, parent, env, counter);
		counter++;
	}
	return (0);
}
