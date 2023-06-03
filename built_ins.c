#include "shell.h"

/**
 * handle_builtins - handles builtins
 *
 * @argv: arguments passed in cmd line
 * @len: length of argv
 * Return: 1 on Success, 0 on Failure
 */
int handle_builtins(char *argv[], __attribute__((unused))int len)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv[0]);
		exit(0);
	}

	return (1);
}
