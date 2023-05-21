#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *command = (char *)malloc(sizeof(char) * 1024);

	prompt("$ ");
	read(STDIN_FILENO, command, 1024);
	command[str_len(command)] = '\0';
	prompt(command);
	_putchar('\n');

	return (0);
}
