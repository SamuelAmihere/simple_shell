#include "main.h"

char *build_err_message(char **msg);
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

/**
 * exit_shell - exits the shell.
 *
 * @msg: message to print.
 * @input: input string.
 * @code: exit code.
 *
 * Return: void.
 */
void exit_shell(__attribute__((unused)) char *msg,
		char *input, int code)
{
	if (msg)
		perror(msg);
	free(input);
	exit(code);

}

/**
 * build_err_message - build error message
 * @msg: message
 * Return: void
 */
char *build_err_message(char **msg)
{
	char *tmp;

	tmp = malloc(sizeof(char) * (_strlen(msg[0]) + _strlen(msg[1]) + 2));
	if (!tmp)
		return (NULL);
	tmp = _strcpy(tmp, msg[0]);
	tmp = _strcat(tmp, msg[1]);

	return (tmp);
}
