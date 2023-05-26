#include "shell.h"

/**
 * executeCommand - executes a command.
 *
 * @argv: array of arguments.
 * @av: array of arguments.
 * @env: array of environment variables.
 *
 * Return: void.
 */

void executeCommand(char *argv[], char **av, char *env[])
{
	pid_t child_pid;
	int child_status;

	/*Create a child process.*/
	child_pid = fork();
	if (child_pid == 0)
	{
		/*This is done by the child process.*/
		if ((execve(argv[0], argv, env)) == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
			exit(1);
		}
	} else if (child_pid < 0)
		exit_shell("Error creating child process", NULL, EXIT_FAILURE);
	else
		wait(&child_status);
}
