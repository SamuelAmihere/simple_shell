#include "shell.h"
#include <stdbool.h>

/**
* shell_prompt - runs the shell prompt.
*
* @av: array of arguments.
* @env: array of environment variables.
*
* Return: void.
*/
void shell_prompt(char **av, char **env)
{
	char *argv[MAX_ARGS] = {NULL, NULL}, *input = NULL;
	int argCount;
	size_t n = 0; /*The number of arguments.*/
	ssize_t read = 0; /*The number of characters read.*/

	/* Print the prompt.*/
	while (1)
	{
		if (ISATTY == 1)
		{
			write(STDOUT_FILENO, ">>>> ", 5);
			read = getline(&input, &n, stdin);
			if (read == -1)
				exit_shell("", input, EXIT_FAILURE);
		} else
		{
			read = getline(&input, &n, stdin);
			if (read == -1)
			{
				free(input);
				break;
			}
		}
		if (input[0] == '\n')
			continue;

		remove_newline(input);
		argCount = tokenizeArgs(input, argv, " ");
		if (argCount == 0)
			continue;
		if (handle_builtins(argv, argCount) == 0)
			continue;
		executeCommand(argv, av[0], env);
	}
}
