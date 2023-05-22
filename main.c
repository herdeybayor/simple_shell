#include "shell.h"

/**
 * main - prints a prompt
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *command = (char *)malloc(sizeof(char) * 1024);
	char path_env[1024];

	prompt("($) ");
	read(STDIN_FILENO, command, 1024);
	command[str_len(command)] = '\0';
	prompt(command);
	_putchar('\n');

	printf("argc: %d\n", argc);
	getcwd(path_env, sizeof(path_env));
	printf("path: %s\n", path_env);

	shell_error(argv[0], command);

	/* main loop of the program */
	while (1)
	{
		prompt("($) ");
		read(STDIN_FILENO, command, 1024);
		command[str_len(command)] = '\0';

		if (str_cmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}
	}

	return (0);
}
