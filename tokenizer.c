#include "main.h"

/**
 * token - function to tokenize the buffer
 * @buffer: the buffer
 * Return: argv value
 */
char **token(char *buffer)
{
	char **argv;
	char *toked;
	int i;

	argv = calloc(1024, sizeof(char *));
	if (!argv)
		return (NULL);

	toked = strtok(buffer, " \n\t");

	if(toked == NULL)
		return (NULL);

	for(i = 0; i < 1024 && toked != NULL; i++)
	{
		argv[i] = toked;
		toked = strtok(NULL, " \n\t");
	}
	argv[i] = NULL;

	return (argv);
}
