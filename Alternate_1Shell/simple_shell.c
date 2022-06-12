#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char cmd[100], command[100], *parameters[20];
	//environment variable
	char *envp[] = {(char *) "PATH=/bin", 0};
	while (1){   //repeat forever
		type_prompt();
		read_command ( command, parameters); //read input from terminal
		if ( fork() != 0)   //parent
			wait (NULL);    //WAIT FOR CHILD
		else{
			strcpy ( cmd, "/bin/" );
			strcat ( cmd, command );
			execve ( cmd, parameters, envp ); //execute command
		}
		if ( strcmp ( command, "exit" ) == 0 )
			break;
	}
	return 0;
}
