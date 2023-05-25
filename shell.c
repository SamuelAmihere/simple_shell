#include "main.h"

/**
 * free_sh - free shell
 * @sh: shell
 * Return: void
 */
void free_sh_data(shell_app *sh)
{
	unsigned int c;

	c = 0;

	for (; sh->sh_environ[c]; c++)
		free(sh->sh_environ[c]);
	free(sh->sh_environ);
	free(sh->pid);
}

/**
 * set_shell_data - set shell data
 * @sh: shell structure
 * @av: arguments
 * Return: void
 */
void set_shell_data(shell_app *sh, char **av)
{
	unsigned int c;

	sh->counter = 1;
	sh->av = av;
	sh->inp = NULL;
	sh->args = NULL;
	sh->status = 0;

	/*count global environs*/
	c = 1;
	while (environ[c - 1])
		c++;

	/*create local environs*/
	sh->sh_environ = malloc(sizeof(char *) * (c + 1));

	/*Assign local variables*/
	for (c = 0; environ[c]; c++)
	{
		sh->sh_environ[c] = _strdup(environ[c]);
	}

	sh->sh_environ[c] = NULL;

}

/**
 * main - Entry point to simpliie shell program
 *
 * @argc: argument counts
 *
 * @argv: vector of arguments
 *
 * Return: 0 always on success
 */
int main(__attribute__((unused))int argc, char **argv)
{
	shell_app shell;

	/*signal(SIGINT, get_signalint);*/
	set_shell_data(&shell, argv);

	shell_prompt(&shell);
	/*free_sh_data(&shell)*/
	return (0);
}
