#include "../include/shell.h"

/**
 * prompt - prints a prompt
 * @c: character argument
 * Return: void
 */
void prompt(char *c)
{
	while (*c != '\0')
	{
		_putchar(*c);
		c++;
	}
}

/**
 * shell_error - prints a prompt
 * @program_path: character argument
 * Return: void
 */
void shell_error(char *program_path)
{
	prompt(program_path);
	prompt(": No such file or directory\n");
}
