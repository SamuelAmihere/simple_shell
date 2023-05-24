#include "main.h"

/**
 * get_signalint - Handles the ^C signal
 * @sg: signal
 * Return: void
 */
void get_signalint(int sg)
{
	(void)sg;

	write(STDOUT_FILENO, "\n^-^ ", 5);
}
