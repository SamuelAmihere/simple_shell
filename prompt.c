#include "main.h"


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
	size_t n = 0;
	ssize_t read = 0;

	while (1)
	{
		if (ISATTY)
			write(STDOUT_FILENO, ">>>> ", 5);
		read = getline(&input, &n, stdin);
		if (read == -1)
		{
			exit_shell("", input, EXIT_FAILURE);
		}

		i = 0;
		if (input[i] == '\n')
			continue;
		while (input[i])
		{
			if (input[i] == '\n')
				input[i] = '\0';
			i++;
		}

		argv[0] = input;
		executeCommand(argv, av, env);
	}
}

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
	char *msg[MAX_ARGS];

	msg[0] = av[0];
	msg[1] = ": No such file or directory\n";

	child_pid = fork();

	if (child_pid == 0)
	{
		if ((execve(argv[0], argv, env)) < 0)
			exec_err(msg);

	} else if (child_pid < 0)
		exit_shell("Error creating child process",
				NULL, EXIT_FAILURE);
	else
		wait(&child_status);

}
