#include "main.h"

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
int main(int argc, char **argv, __attribute__((unused)) char **env)
{
	if (argc == 1)
		start_shell(argv, env);

	return (0);
}
