#include "shell.h"

/**
 * shell_prompt - runs the shell prompt.
 *
 * @av: array of arguments.
 * @env: array of environment variables.
 *
 * Return: void.
 */
void shell_prompt(char **av, char **env)
{
	char *argv[MAX_ARGS] = {NULL, NULL}, *input = NULL;
	int argCount;
	size_t n = 0; /*The number of arguments.*/
	ssize_t read = 0; /*The number of characters read.*/
	char *temp;

	/* Print the prompt.*/
	while (1)
	{
		if (ISATTY)
		{
			write(STDOUT_FILENO, ">>>> ", 5);
			read = getline(&input, &n, stdin);
			if (read == -1)
				exit_shell("", input, EXIT_FAILURE);
		} else
		{
			read = getline(&input, &n, stdin);
			if (read == -1)
			{
				free(input);
				break;
			}
		}
		if (input[0] == '\n')
			continue;
		
		remove_newline(input);
		argCount = tokenizeArgs(input, argv, " ");
		if (argCount == 0)
			continue;

		temp = path_find(argv);
		if (temp != NULL)
		{
			update_array(argv, temp);
		}
		else
			continue;
		
		if (!argv[0])
			argv[0] = temp;

		executeCommand(argv, av[0], env);
	}

}

/**
 * update_array - Updates elements of an array
 *
 * @argv: string array
 * @str: new string
 *
 * Return: Nothing
 */
void update_array(char *argv[], char *str)
{

	int i = 0;

	if (!argv || !str)
		return;

	while (argv[i])
	{
		if (_strcmp(argv[i], str) == 0)
		{
			i++;
			continue;
		}
		argv[i] = str;
		i++;
	}

}
