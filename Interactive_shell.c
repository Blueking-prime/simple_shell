#include "main.h"

/**
* main - Entry Point
*
* Return: (Always/Success)
*/

int main(void)
{
	pid_t c_pid;
	int exec_ret, status;
	char *newargv[] = {NULL, NULL};
	char command[1024];
	char *exit_command = "exit";

	while (*command != *exit_command)
	{
		newargv[0] = command;

		printf("$ ");
		scanf("%s", command);

		if (*command == *exit_command)
		{
			break;
		}

		c_pid = fork();
		if (c_pid == -1)
		{
			perror("Error: Child process not created");
			return (1);
		}

		/*Start of Child*/
		if (c_pid == 0)
		{
			exec_ret = execve(newargv[0], newargv, NULL);
			if (exec_ret == -1)
			{
				perror("Error: command did not execute");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}

	}
	/*End of child*/

	return (0);
}