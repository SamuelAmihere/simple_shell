#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
/**
 * path_find - finds the path to the command
 * @argv: pointer to an array of commands
 * * Return: pointer to thr path , 0 if not found
 */
char *path_find(char **argv)
{
	char *path = getenv("PATH");
	char *dir = NULL;
	char *path_hold = strtok(path, ":");
	int dir_len = _strlen(argv[0]);
	size_t path_len;

	while (path_hold != NULL)
	{
		path_len = _strlen(path_hold);
		dir = malloc(dir_len + path_len + 2);
		if (dir == NULL)
			return (NULL);

		_strcpy(dir, path_hold);
		_strcat(dir, "/");
		_strcat(dir, argv[0]);
		/*check for permissions */
		if ((access(dir, F_OK) == 0))
			return (dir);

		free(dir);
		/*check if all the path have been tokenized yet */
		path_hold = strtok(NULL, ":");
	}
	return (dir);
}

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
	/*Check if the first part is /bin/.*/
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
	char *bin_p = "/bin/";
	DIR *directory = opendir(bin_p);
	struct dirent *readir;
	char *path = NULL;

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
			else
			{
				closedir(directory);
				return (NULL);
			}
		}
	}
	closedir(directory);
	return (NULL);
}
