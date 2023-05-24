#include "main.h"

/**
 * check_cmd_path - checks if the command is inbuilt
 * commands.
 *
 * @cm: command to check.
 *
 * Return: 1 if the command is in the inbuilt commands, 0 if not.
 */
int check_cmd_path(char *cm)
{
	int i = 0, j = 0;
	char *root = "/bin/", *tmp, *path;

	tmp = malloc(sizeof(char) * _strlen(cm) + 1);

	if (tmp == NULL)
		return (0);
	while (root[i] != '\0')
	{
		if (root[i] != cm[i])
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	while (cm[i] != '\0')
	{
		tmp[j] = cm[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	path = check_file(tmp);
	if (path)
	{
		free(path);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

/**
 * check_file - checks and builds path if the command file exists.
 *
 * @cm: command to check.
 *
 * Return: 1 if the file exixts, 0 if not.
 */
char *check_file(char *cm)
{
	char *bin_p = "/bin/", *path = NULL;
	DIR *directory = opendir(bin_p);
	struct dirent *readir;

	if (directory == NULL)
		return (NULL);
	while ((readir = readdir(directory)) != NULL)
	{
		if (_strcmp(readir->d_name, cm) == 0)
		{
			path = build_path(bin_p, cm);
			if (path)
			{
				closedir(directory);
				return (path);
			}
		}
	}
	closedir(directory);
	return (NULL);
}

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
