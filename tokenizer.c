#include "main.h"

/**
 * token - function to tokenize the captured input
 * @buffer: input to delimit
 * Return: a null-terminated double pointer pointing to the tokenized arguments
 */
char **token(char *buffer)
{
	char **argv;
	char *toked;
	int i;

	toked = strtok(buffer, " \n\t");

	if (toked == NULL)
		return (NULL);

	argv = calloc(1024, sizeof(char *));

	if (!argv)
		return (NULL);

	for (i = 0; i < 1024 && toked != NULL; i++)
	{
		argv[i] = toked;
		toked = strtok(NULL, " \n\t");
	}

	argv[i] = NULL;

	return (argv);
}
