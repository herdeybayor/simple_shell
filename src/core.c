#include "../include/shell.h"
/**
 * interactive - runs the shell in interactive mode
 * @command: command to execute
 * @argv: argument vector
 * @env_args: environment arguments
 * Return: 0 on success
 */
int interactive(char *command, char *argv[], char *env_args[])
{
	int parent;
	/* main process */
	while (1)
	{
		prompt(":) ");
		read(0, command, 1024);
		command[str_len(command)] = '\0';
		if (!str_cmp(command, "exit"))
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		/* fork a child process */
		parent = fork();
		if (!parent)
		{
			execve(command, argv, env_args);
			shell_error(*argv);
			free(command);
			exit(EXIT_FAILURE);
		}
		else 
		{
			wait(NULL);
			continue;
		}
		break;
	}

	return (EXIT_SUCCESS);
}
