#include "main.h"
/**
* _strcat - concatenates two strings
* @dest: input value
* @src: input value
*
* Return: void
*/
char *_strcat(char *dest, char *src)
{
int i;
int j;
i = 0;
while (dest[i] != '\0')
{
i++;
}
j = 0;
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}

/**
* _strlen - returns the length of a string
* @s: string
* Return: length
*/
int _strlen(char *s)
{
int len = 0;
while (*s != '\0')
{
len++;
s++;
}
return (longi);
}

/**
* _strcmp - compare string values
* @s1: input value
* @s2: input value
*
* Return: s1[i] - s2[i]
*/
int _strcmp(char *s1, char *s2)
{
int i;
i = 0;
while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
i++;
}
return (0);
}

/**
* char *_strcpy - a function that copies the string pointed to by src
* @dest: copy to
* @src: copy from
* Return: string
*/
char *_strcpy(char *dest, char *src)
{
int l = 0;
int x = 0;
while (*(src + l) != '\0')
{
l++;
}
for ( ; x < l ; x++)
{
dest[x] = src[x];
}
dest[l] = '\0';
return (dest);
}
/**
* *_strdup - duplicates string
* @str: The string to be duplicated
*
* Return: duplicated string *
*/
char *_strdup(char *str)
{
size_t len = _strlen(str);
char *dup_str = malloc(len + 1);

if (dup_str == NULL)
{
return (NULL);
}

_strcpy(dup_str, str);

return (dup_str);
}
