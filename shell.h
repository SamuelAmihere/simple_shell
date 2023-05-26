#ifndef _SHELL_H
#define _SHELL_H

/************************************************************/
/***|                   Includes                         |***/
/************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>

/************************************************************/
/***|                   Define Macros                    |***/
/************************************************************/
#define ISATTY isatty(STDIN_FILENO)
#define MAX_ARGS 10
#define MAX_ARG_LENGTH 100

/*********************** Structures *********************/
/**
 * struct sh - shell application
 * @sh_environ: shell environment
 * Return: void
*/
typedef struct sh
{
	char **sh_environ;
} shell_app;


/**
 * struct array_shells - shell built ins
 * @shell_name: shell name
 * @func: function
 * Return: void
 */
typedef struct array_shells
{
	char *shell_name;
	int (*func)(shell_app *sh);
} sh_built_ins;



/************************************************************/
/***|                   Prototypes                       |***/
/************************************************************/
/* main.c */



/* shell_data.c */
void set_shell_data(shell_app *sh);
void free_sh_data(shell_app *sh);


/* prompt.c */
void shell_prompt(char **av, char **env);






/* execute_command.c */
void executeCommand(char *argv[], char **av, char *env[]);





/**************** helpers.c ***************/
void show_prompt(void);



/* frees.c */


/* helpers_string.c */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);



/* exits.c */
void exit_shell(__attribute__((unused)) char *msg, char *input, int code);





/**/

#endif
