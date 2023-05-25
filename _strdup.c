#include "main.h"

char *_strdup(char *str)
{
	size_t len = _strlen(str);
	char *dup_str = malloc (len + 1);
	if (dup_str == NULL)
	{
		return(NULL);
	}
	_strcpy(dup_str, str);
	return (dup_str);
}

