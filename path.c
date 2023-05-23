#include "main.h"
#include <stdlib.h> 
#include <string.h> 
#include <sys/stat.h>


char *path_find(char **argv)
{
char *path = getenv("PATH");
char *dir;
char *path_hold = strtok(path, ":");
struct stat buffer;

int dir_len = _strlen(argv[0]);

while (path_hold != NULL)
{
size_t path_len = _strlen(path_hold);
dir = malloc(dir_len + path_len + 2);

if (dir == NULL) {
return (NULL); /* allocation failed*/
}

_strcpy(dir, path_hold);
_strcat(dir, "/");
_strcat(dir, argv[0]);
_strcat(dir, '\0');

if (stat(dir, &buffer) == 0) 
{
/*File exists, return the path*/
return (dir);
}

free(dir);
path_hold = strtok(NULL, ":");
}

/* File not found in any of the directories*/
return (0);
}
