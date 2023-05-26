#include "shell.h"

/**
 * build_path - builds the path to the command.
 *
 * @root: root path.
 * @cm: command to check.
 *
 * Return: pointer to the path.
 */
char *build_path(char *root, char *cm)
{
	char *str;

	str = malloc(sizeof(char) * (_strlen(cm) + _strlen(root) + 1));
	if (str == NULL)
		return (NULL);
	str = _strcpy(str, root);
	str = _strcat(str, cm);
	return (str);
}
