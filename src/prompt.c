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

/**
 * shell_error - prints a prompt
 * @program_path: character argument
 * @command: character argument
 * Return: void
 */
void shell_error(char *program_path, char *command)
{
	prompt(program_path);
	prompt(": 1: ");
	prompt(command);
	prompt(": not found\n");
}

/**
 * str_cmp - prints a prompt
 * @s1: character argument
 * @s2: character argument
 * Return: void
 */
int str_cmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
