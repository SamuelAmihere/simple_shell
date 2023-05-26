#include "shell.h"

/**
 * _strlen - returns the length of a string.
 *
 * @s: input string.
 *
 * Return: length of a string.
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: first string.
 * @s2: second string.
 *
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		op = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (op);
}
