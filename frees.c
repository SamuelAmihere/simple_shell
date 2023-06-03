#include "shell.h"

/**
 * free_vec - frees array vector and its elements
 *
 * @arr: array vector to free
 * @n: length of arr
 * Return: nothing
 */
void free_vec(char **arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
}
