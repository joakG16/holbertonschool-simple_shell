#include "main.h"

/**
 *
 *
 *
 */
int main(void)
{
	char *buffer = NULL;
	size_t buff_size = 0;
	char **args;

	while (1)
	{
		signal(SIGINT, catchsig);

		shprompt();

		if (getline(&buffer, &buff_size, stdin) == -1)
		{
			break;
		}
		if (buffer[0] == '\n')
			continue;

		args = token(buffer);
		vexec(args);
	}
	free(buffer);
	return(0);
	
}
void catchsig(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 2);
		shprompt();
	}
}
int shprompt()
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
	}
	return(0);
}
