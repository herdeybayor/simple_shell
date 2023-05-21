#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *command = NULL;

	prompt("$ ");
	read(0, command, 1024);
	prompt(command);
	_putchar('\n');

	return (0);
}
