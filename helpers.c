#include "shell.h"

/************************* FOR PROMPT ****************************/
/**
 * show_prompt - prints the prompt.
 *
 * Return: void.
 */
void show_prompt(void)
{
	if (ISATTY)
		/* Print the prompt.*/
		printf(">>>> ");
}
