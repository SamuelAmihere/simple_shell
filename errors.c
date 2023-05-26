#include "shell.h"

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
