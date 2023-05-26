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

/**
 * exec_err - prints error message
 * @msg: message
 * Return: void
 */
void exec_err(char **msg)
{
	char *str;
	int i;

	str = build_err_message(msg);

	if (!str)
		return;
	i = _strlen(str);
	write(STDERR_FILENO, str, i);
	free(str);
}
