#include "shell.h"

/**
 * exit_shell - exits the shell.
 *
 * @msg: message to print.
 * @input: input string.
 * @code: exit code.
 *
 * Return: void.
 */
void exit_shell(__attribute__((unused)) char *msg, char *input, int code)
{
	if (msg)
		perror(msg);
	free(input);
	exit(code);
}
