#include "shell.h"
/**
 * main - Entry point to simple shell program
 *
 * @argc: argument counts
 *
 * @argv: vector of arguments
 *
 * @env: vector of environment variables
 *
 * Return: 0 always on success
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		/*Run the shell.*/
		shell_prompt(argv, env);

	return (0);
}
