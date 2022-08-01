#include "main.h"

/**
 *
 *
 *
 */
int vexec(char **args)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error: ");
		return(1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == - 1)
		{
			perror("Error: ");
			return (1);
		}
	}
	else
		wait(&status);
	
	free(args);
	return (0);
}
