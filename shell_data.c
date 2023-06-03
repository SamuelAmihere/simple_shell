#include "shell.h"

/**
 * set_vector - copy data from one vector to another
 *
 * @dest: destination to copy to
 * @src: source of vector
 * @len: number of items in src
 *
 * Return: nothing
 */
void set_vector(__attribute__((unused))char **dest, char *src[], int len)
{
	char **paths;
	int idx;

	paths = malloc(sizeof(char *) * (len + 2));
	if (!paths)
		return;

	for (idx = 0; src[idx]; idx++)
		paths[idx] = src[idx];

	if (paths[idx] != NULL)
		paths[idx + 1] = NULL;

	for (idx = 0; paths[idx]; idx++)
		;
	dest = paths;
	free_vec(paths, idx);
}
