#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
/**
 * path_find - finds the path to the command
 * @argv: pointer to an array of commands
 *
 * Return: pointer to thr path , 0 if not found
 */
<<<<<<< HEAD
char *path_find(char **argv)
=======

char *path_find(char **cmd)
>>>>>>> b9bb8d1b148d83132c3a9692dc4e123c5a5ffc1e
{
char *path = getenv("PATH");
char *dir;
char *path_hold = strtok(path, ":");
<<<<<<< HEAD
=======
struct stat buffer;
/*calculate the length of string and store in dir_len*eaclear
 * 
>>>>>>> b9bb8d1b148d83132c3a9692dc4e123c5a5ffc1e
int dir_len = _strlen(argv[0]);
while (path_hold != NULL)
{
size_t path_len = _strlen(path_hold);
dir = malloc(dir_len + path_len + 2);
if (dir == NULL)
{
return (NULL);
}
_strcpy(dir, path_hold);
_strcat(dir, "/");
_strcat(dir, argv[0]);
_strcat(dir, '\0');
/*check if stat retrieved infor successesfuly */
if ((access(dir, F_OK) == 0))
{
return (dir);
}
free(dir);
/*check if all the path have been tokenized yet */
path_hold = strtok(NULL, ":");
}
return (0);
}
