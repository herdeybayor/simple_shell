#include "shell.h"

/**
 * main - prints a prompt
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	size_t size = 1024;
	char *command = (char *)malloc(sizeof(char) * size);
	char path_env[1024], *env_args[] = {(char *)0};

	while (argc--)
		printf("%s\n", argv[argc]);
	/* argc not in use */
	/* (void)argc; */

	getcwd(path_env, sizeof(path_env));
	/* printf("CWD = %s\n\n", path_env); */

	/* check if the shell is non-interactive */
	if (!isatty(STDIN_FILENO))
	{
		getline(&command, &size, stdin);
		command[str_len(command)] = '\0';
		execve(command, argv, env_args);
		shell_error(argv[0]);
		exit(0);
	} else
	{
		interactive(command, argv, env_args);
	}

	free(command);

	return (0);
}
