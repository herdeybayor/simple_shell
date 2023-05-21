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

/**
 * str_len - prints a prompt
 * @s: character argument
 * Return: void
 */
int str_len(char *s)
{
	int i = 0;

	while (*s >= 32 && *s <= 126)
	{
		i++;
		s++;
	}

	return (i);
}
