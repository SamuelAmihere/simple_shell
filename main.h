#ifndef MAIN_H
#define MAIN_H

/*macros*/
#define ISATTY(fileno) isatty(fileno)
#define MAX_ARG_Token 100
#define MAX_ARGS 10
#define DELIMS " \n\t\a\r"
#define BUF_SIZE 1024
#define FLUSH_BUF -1
#define SIGINT 0

/*header files*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <dirent.h>

/*********************** Structures *********************/
/**
 * struct sh - shell application
 * @pid: process id
 * @status: status
 * @inp: input
 * @av: arguments
 * @counter: counter
 * @args: arguments
 * @sh_environ: shell environment
 * Return: void
*/
typedef struct sh
{
	char *pid;
	int status;
	char *inp;
	char **av;
	int counter;
	char **args;
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

/*function prototypes*/
extern char **environ;
void envi(void);
int shellexit(char **cmd, char *lineeptr);
void free_all(char **cmd, char *lineptr, char **environ);
void free_sh_data(shell_app *sh);
int tokenizeArgs(char *input, char **arguments, char *delim);

/*prompt*/
void shell_prompt(shell_app *sh);
void executeCommand(char *argv[], shell_app *sh);

/*shell_utils*/
void get_sh_pid(int sig);

/*signal_handler*/
void get_signalint(int sg);

/*io_utils*/
int _putchar(char c);
int _puts(char *str);
int _count_char(char *str);
int _atoi(char *s);
char *_itos(int n);
int _count_digits(int n);

/*str_utils*/
size_t _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
/*build ins*/
char *path_find(char **argv);
int (*get_sh_builtin(char *cm))(shell_app *);

/*checkers*/
int check_cmd_path(char *cm);
char *check_file(char *cm);
char *build_path(char *root, char *cm);

/*errors*/
void exit_shell(__attribute__((unused)) char *msg, char *input, int code);
void exec_err(char *msg);
#endif
