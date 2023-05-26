#include "shell.h"

/**
 * remove_newline - Removes newline character
 *
 * @bf: pointer to the string
 *
 * Return: string
 */
void remove_newline(char *bf)
{
	int i;
	char *pt = bf;

	i = 0;
	while (pt[i])
	{
		if (pt[i] == '\n')
			pt[i] = '\0';
		i++;
	}
}
