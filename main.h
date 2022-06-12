#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*Shell modes*/
int interactive_mode(char *parent, char **env);
int non_interactive_mode(int argc, char **argv, char **env);

/*Extra functions*/
char *input_prompt(void);
char *format_input(char *command);
int check_if_exit(char *command);
int check_if_env(char *command, char **env);
char *check_path(char *command);

/*Extra functions*/
void _printenv(char **env);
void execute_command(char *command, char *parent, char **env, int counter);

/*Print and other Standard functions*/
/**
* int _puts(char *str);
* int _putchar(int c);
* int _putserr(char *str);
* int _puterrchar(int c);
*/

#endif /* MAIN_H */
