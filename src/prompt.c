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
 * Return: void
 */
void shell_error(char *program_path)
{
	prompt(program_path);
	prompt(": No such file or directory\n");
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

/**
 * str_concat - concatenates two strings
 * @s1: character argument
 * @s2: character argument
 * Return: string
 */
char *str_concat(char *s1, char *s2)
{
	char *s = (char *)malloc(sizeof(char) * 1024);
	int i = 0, j = 0;

	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		s[i] = s2[j];
		i++;
		j++;
	}

	s[i] = '\0';

	return (s);
}

/**
 * str_includes - check if a string includes another string
 * @s1: character argument
 * @s2: character argument
 * Return: (1) if s1 includes s2, (0) otherwise
 */
int str_includes(char *s1, char *s2)
{
	int i = 0, j = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j])
			{
				i++;
				j++;
			}

			if (s2[j] == '\0')
				return (1);
		}

		i++;
	}

	return (0);
}
