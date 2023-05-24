#include "main.h"



/**
 * shell_prompt - creates shell
 *
 * @sh: shell
 *
 * Return: nothing
 */
void shell_prompt(__attribute__((unused)) shell_app * sh)
{
	char *argv[MAX_ARGS], *input = NULL;
	int i, argCount, flag = 1;
	size_t n = 0;
	ssize_t read = 0;

	while (flag)
	{
		if (ISATTY(STDIN_FILENO))
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
		argCount = tokenizeArgs(input, argv, DELIMS);
		if (argCount == -1)
			continue;
		sh->inp = input;
		executeCommand(argv, sh);
	}
}

/**
 * executeCommand - executes a command.
 *
 * @argv: array of arguments.
 *
 * @sh: shell
 *
 * Return: void.
 */
void executeCommand(char *argv[], shell_app *sh)
{
	pid_t child_pid;
	char *cmd = sh->av[0];
	char *s = ": No such file or directory\n";
	char *msg[MAX_ARGS];

	msg[0] = cmd;
	msg[1] = s;

	child_pid = fork();
	if (child_pid == 0)
	{
		if ((execve(argv[0], sh->av, sh->sh_environ)) < 0)
			exec_err(msg);

	} else if (child_pid < 0)
		exit_shell("Error creating child process", NULL, EXIT_FAILURE);
	else
		wait(&(sh->status));

}
