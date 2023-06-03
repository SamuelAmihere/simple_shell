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
void set_vector(char **dest, char *src[], int len);

/* prompt.c */
void shell_prompt(char **av, char **env);
void update_array(char *argv[], char *str);


/* execute_command.c */
void executeCommand(char *argv[], char *av, char *env[]);


/**************** helpers.c ***************/
void show_prompt(void);

/* args.c */
int tokenizeArgs(char *input, char **arguments, char *delim);
void free_sh_data(shell_app *sh);

/* frees.c */
void free_vec(char **arr, int n);

/* string.c */
char *_strdup(char *str);
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);

/* string_proc.c*/
void remove_newline(char *bf);

/* built_ins.c */
int handle_builtins(char *argv[], __attribute__((unused))int len);

/* exits.c */
void exit_shell(__attribute__((unused)) char *msg, char *input, int code);
void exec_err(char **msg);


/* errors.c*/
char *build_err_message(char **msg);


/* paths.c*/
char *build_path(char *root, char *cm);


/* path.c */
char *path_find(char **argv);
char *check_file(char *cm);
int check_cmd_path(char *cm);
#endif
