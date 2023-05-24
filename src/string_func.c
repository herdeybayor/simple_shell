#include "../include/shell.h"

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

/**
 * tokenize - prints a prompt
 *
 * @str: the string to be tokenized
 * @delim: the delimiters to tokenize the string
 * Return: An array of strings (tokens)
 */
char **tokenize(char *str, char *delim)
{
	char **tokens = (char **)malloc(1024 * sizeof(char *));
	char *token;
	int i = 0;

	token = strtok(str, delim);
	while (token != NULL)
	{
		*(tokens + i) = token;
		token = strtok(NULL, delim);
		i++;
	}
	*(tokens + i) = NULL;

	return (tokens);
}
