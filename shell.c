#include "main.h"

/**
 * main - the main function
 * Return: void
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

		if (getline(&buffer, &buff_size, stdin) == EOF)
		{
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 2);

			exit(EXIT_FAILURE);
		}
		if (buffer[0] == '\n')
			continue;

		args = token(buffer);
		vexec(args);
	}
	free(buffer);
	return (0);
}
/**
 * catchsig - function to catch the signal
 * @sig: the signal
 * Return: void
 */
void catchsig(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 2);
		shprompt();
	}
}
/**
 * shprompt - function to verify if it's from terminal or file
 * Return: void
 **/
int shprompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
	}
	return (0);
}
