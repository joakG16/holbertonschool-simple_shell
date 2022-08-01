#include "main.h"

/**
 *
 *
 *
 */
int main(void)
{
	char *buffer;
	size_t buff_size = 32;

	while (1)
	{
		write(1, "#cisfun$ ", 10);
		buffer = malloc(buff_size * sizeof(char));

		if (buffer == NULL)
			return(1);

		if (getline(&buffer, &buff_size, stdin) == -1)
		{
			free(buffer);
			break;
		}
		
	}
	return(0);

}
