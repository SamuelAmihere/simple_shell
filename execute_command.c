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
	int child_status, cmdpth, inb = 0;
	char *msg[MAX_ARGS], *pth;

	msg[0] = av;
	msg[1] = ": No such file or directory\n";

	pth = check_file(argv[0]);
	cmdpth = check_cmd_path(argv[0]);
	if (pth)
		argv[0] = pth;
	inb = check_cmd_path(argv[0]);
	if (inb == 1)
	{
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
			exit_shell("Error creating child process",
					NULL, EXIT_FAILURE);
		else
			wait(&child_status);
	}
	if (!cmdpth && !pth && !inb)
		exec_err(msg);
	free(pth);
}
