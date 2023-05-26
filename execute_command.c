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

void executeCommand(char *argv[], char *av, char *env[])
{
	pid_t child_pid;
	int child_status;
	char *msg[MAX_ARGS];

	msg[0] = av;
	msg[1] = ": No such file or directory\n";

	/*Create a child process.*/
	child_pid = fork();
	if (child_pid == 0)
	{
		/*This is done by the child process.*/
		if ((execve(argv[0], argv, env)) == -1)
		{
			free(argv[0]);
			exec_err(msg);
			exit(1);
		}
	} else if (child_pid < 0)
		exit_shell("Error creating child process", NULL, EXIT_FAILURE);
	else
		wait(&child_status);
}
