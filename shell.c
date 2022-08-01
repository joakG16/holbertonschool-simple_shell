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

	while (1)
	{
		write(1, "#cisfun$ ", 10);

		if (getline(&buffer, &buff_size, stdin) == -1)
		{
			break;
		}
	}
	free(buffer);
	return(0);

}
