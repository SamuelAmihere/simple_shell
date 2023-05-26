#include "shell.h"

/**
 * _strdup - duplicate string
 *
 * @str: string to be duplicated
 *
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	int i;
	char *new_str;

	/*return NULL if string is NULL*/
	if (str == NULL)
		return (NULL);
	/*count number of characters in the string*/
	for (i = 0; str[i] != '\0'; i++)
	/*create memory to store new string*/
	new_str = malloc((sizeof(char) * i) + 1);
	/*return NULL if malloc fails*/
	if (new_str == NULL)
		return (NULL);
	/*copy string from str to new_string*/
	for (i = 0; str[i] != '\0'; i++)
	{
		new_str[i] = str[i];
	}
	/*terminate new string with null character*/
	new_str[i] = '\0';

	return (new_str);
}

/**
 * _strcpy - copy string to from source (src)
 * to destination (dest)
 *
 * @dest: the location to copy strin to
 * @src: the string to be copied
 *
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);

}

/**
 * _strcmp - compare two strings
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if two strings are equal
 * a negative value if the first string is less than the second
 * a positive value if the first is greater than the second
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	/*check if eithr str has reached null yet*/
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		/*compare  they point to equal srings */
		if (str1[i] == str2[i])
		{
			i++;
			continue;
		}
		/*check if one string is greateror less than the other*/
		else if (str1[i] > str2[i])
			return (1);
		else
			return (-1);
	}

	/*check if both  strings have ended at same string */
	if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	/*checkif any string has reached NULL*/
	else if (str1[i] == '\0')
		return (-1);
	else
		return (1);
}

/**
 * _strlen - calculate the lenght of a string
 * @str: pointer to  a string to calculate
 * Return:  number  of bytes in the string
 */
size_t _strlen(char *str)
{
	int n = 0;
	/*check if the value of n has not reached NULL*/
	while (str[n] != '\0')
	{
		n++;
	}

	return (n);
}

/**
 * _strcat - appends strings
 * @src:the source of string to be appended
 * @dest: the destination to append to
 *Return: 0;
 ** if src is NULL ||if dest and source pint to same string
 */
char *_strcat(char *dest, char *src)
{
	int count = 0, count2 = 0;
	char *temp = dest;

	while (*(temp + count) != '\0')
		count++;

	while (count2 >= 0)
	{
		*(temp + count) = *(src + count2);
		if (*(src + count2) == '\0')
			break;
		count++;
		count2++;
	}
	return (temp);
}
