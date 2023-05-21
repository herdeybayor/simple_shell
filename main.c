#include "shell.h"

/**
 * main - prints a prompt
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp[])
{
	char *command = (char *)malloc(sizeof(char) * 1024);
	int i;

	prompt("$ ");
	read(STDIN_FILENO, command, 1024);
	command[str_len(command)] = '\0';
	prompt(command);
	_putchar('\n');

	for (i = 0; envp[i] != NULL; i++)
		printf("Environment variable %d: %s\n", i, envp[i]);

	while (argc--)
		printf("%s\n", *argv++);

	free(command);

	return (0);
}
