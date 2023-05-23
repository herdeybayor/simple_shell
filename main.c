#include "shell.h"

/**
 * main - prints a prompt
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *command = (char *)malloc(sizeof(char) * 1024);
	char *env_args[] = {(char *)"/bin", (char *)"/usr/bin", NULL};
	char path_env[1024];
	int parent;

	printf("argc = %d\n", argc);
	while (argc--)
		printf("%s\n", argv[argc]);

	getcwd(path_env, sizeof(path_env));
	printf("CWD = %s\n\n", path_env);

	/* main loop of the program */
	while (1)
	{
		prompt("#cisfun$ ");
		read(0, command, 1024);
		command[str_len(command)] = '\0';
		if (!str_cmp(command, "exit"))
		{
			free(command);
			exit(0);
		}
		/* fork a child process to execute the command */
		parent = fork();
		if (!parent)
		{
			execve(command, argv, env_args);
			shell_error(argv[0], command);
			exit(0);
		} else
		{
			wait(NULL);

			continue;
		}
		break;
	}

	return (0);
}
