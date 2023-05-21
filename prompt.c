#include "shell.h"

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
