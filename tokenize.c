#include "shell.h"

/**
 * tokenizeArgs - tokenizes the arguments.
 *
 * @input: input string.
 * @arguments: array of arguments.
 * @delim: delimiter.
 *
 * Return: number of arguments.
 */
int tokenizeArgs(char *input, char **arguments, char *delim)
{
	int argCount = 0;
	char *token = NULL;

	token = strtok(input, delim);
	while (token != NULL)
	{
		arguments[argCount] = token;
		argCount++;

		/*Check if the number of arguments exceeds the maximum.*/
		if (argCount >= MAX_ARGS)
		{
			write(STDOUT_FILENO, "Too many arguments", 18);
			break;
		}
		/*Get the next token.*/
		token = strtok(NULL, delim);
	}
	return (argCount);
}
