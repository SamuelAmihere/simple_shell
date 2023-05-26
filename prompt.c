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
	char *argv[MAX_ARGS], *input = NULL;
	int i;
	size_t n = 0; /*The number of arguments.*/
	ssize_t read = 0; /*The number of characters read.*/

	/* Print the prompt.*/
	while (1)
	{
		show_prompt();

		read = getline(&input, &n, stdin);
		if (read == -1)
			exit_shell("", input, EXIT_FAILURE);
		i = 0;
		if (input[i] == '\n')
			continue;
		/*Remove the newline character from the end of the input.*/
		while (input[i])
		{
			if (input[i] == '\n')
				input[i] = 0;
			i++;
		}
		argv[0] = input;
		/*Execute the command.*/
		executeCommand(argv, av, env);
	}
}
