#include "main.h"

/**
 * main - main body of our shell
 * @ac: unused
 * @av: unused
 * @env: array of strings enviroment variable of the process
 * Return: exit status of child process
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t buff_size = 0;
	char **args;
	int retval = 0;
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
			if (args)
				free(args);
			free(buffer);
			return (retval);
		}
		if (_strcmp(*args, "env") == 0)
		{
			_getenv();
			if (args)
				free(args);
			continue;
		}
		retval = vexec(args, env);
	}
	free(buffer);
	return (retval);
}
/**
 * catchsig - function to check if a SIGINT was typed
 * @sig: the signal catched by the signal()
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
 * shprompt - function to verify input (comes from terminal or not)
 * and print correspondent prompt(or not)
 * Return: 0
 **/
int shprompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
	}
	return (0);
}

/**
 * _getenv - func to print the environment when "env"
 * Return: 0
 */
int _getenv(void)
{
	int string, strenv = 0;

	for (string = 0; environ[string] != NULL; string++)
	{
		write(1, environ[strenv], _strlen(environ[strenv]));
		write(1, "\n", 2);
		strenv++;
	}
	return (0);
}
