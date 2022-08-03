#include "main.h"

/**
 * main - the main function
 * Return: void
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t buff_size = 0;
	char **args;
	(void)(ac);
	(void)(av);

	while (1)
	{
		signal(SIGINT, catchsig);

		shprompt();

		if (getline(&buffer, &buff_size, stdin) == EOF)
			break;

		if (buffer[0] == '\n')
			continue;

		args = token(buffer);

		if (args == NULL)
			break;

		if (_strcmp(*args, "exit") == 0)
		{
			free(buffer);
			return (0);
		}

		vexec(args, env);
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
