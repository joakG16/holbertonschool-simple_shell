#include "main.h"

/**
 *
 *
 *
 */
int vexec(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == - 1)
		{
			perror("Error: ");
		}
	}
}
