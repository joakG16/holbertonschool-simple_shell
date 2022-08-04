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
			if(args)
				free(args);
			free(buffer);
			return (0);
		}
		if (_strcmp(*args, "env") == 0)
		{
			_getenv();
			if(args)
				free(args);
			continue;
		}
		retval = vexec(args, env);
	}
	free(buffer);
	return (retval);
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

/**
 * _getenv - func to get the environment
 * Return: 0
 */
int _getenv()
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
