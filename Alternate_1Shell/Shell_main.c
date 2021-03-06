#include "main.h"

/**
* main - Entry Point
*
* @argc: No of arguments
*
* @argv: Array of arguments
*
* @env: Process environment
*
* Return: (Always/Success)
*/

int main(int argc, char **argv, char **env)
{
	int i;

	if (argc == 1)
	{
		i = interactive_mode(argv[0], env);
		return (i);
	}
	else
	{
		i = non_interactive_mode(argc, argv, env);
		return (i);
	}
}
