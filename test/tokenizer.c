#include "main.h"

/**
 *
 *
 *
 */
char **token(char *buffer)
{
	char **argv = NULL;
	char *buffcpy = strtok(buffer, "\n");

	argv = malloc(2 * sizeof(char*));
	if (argv == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	argv[0] = malloc((strlen(buffer)) * sizeof(char));
	if (argv[0] == NULL)
	{
		free(argv);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	strcpy(argv[0], buffcpy);
	argv[1] = NULL;

	return (argv);
}
