#include "../include/shell.h"

/**
 * run - runs a command
 * @command: command to run
 * @argv: argument vector
 * @env_args: environment arguments
 * Return: 0 on success
 */
int run(char *command, char *argv[], char *env_args[])
{
	execve(command, argv, env_args);
	shell_error(*argv);
	free(command);
	exit(EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

/**
 * execute - executes a command
 * @command: command to execute
 * @argv: argument vector
 * @env_args: environment arguments
 * Return: 0 on success
 */
int execute(char *command, char *argv[], char *env_args[])
{
	int parent;

	parent = fork();
	if (!parent)
	{
		run(command, argv, env_args);
	}
	else
	{
		wait(NULL);
		return (EXIT_SUCCESS);
	}

	return (EXIT_FAILURE);
}

/**
 * interactive - runs the shell in interactive mode
 * @command: command to execute
 * @argv: argument vector
 * @env_args: environment arguments
 * Return: 0 on success
 */
int interactive(char *command, char *argv[], char *env_args[])
{
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
		/* fork child process */
		if(!execute(command, argv, env_args))
			continue;
		break;
	}

	return (EXIT_SUCCESS);
}
