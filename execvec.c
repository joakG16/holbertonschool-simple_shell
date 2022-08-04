#include "main.h"

/**
 * 
 *
 *
 */
int vexec(char **args, char **enve)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{

		if (execve(args[0], args, enve) == -1)
		{
			perror("Error");
		}
		free(args);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		free(args);
		return(WEXITSTATUS(status));
	}
	free(args);
	return (0);
}
