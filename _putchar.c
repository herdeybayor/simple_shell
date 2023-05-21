#include "shell.h"

/**
 * _putchar - puts a character to the standard output
 *
 * @c: character argument
 * Return: char c and return -1 if error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
