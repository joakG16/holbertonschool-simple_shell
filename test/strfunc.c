#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strdup - main
 * @str: string
 * Return: pointer to allocated memory
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0;
	if (str == NULL)
	{
		return (NULL);
	}
	s = malloc(sizeof(char) * _strlen(str) + 1);
	if (s == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < (int)_strlen(str); i++)
		{
			s[i] = str[i];
		}
		s[i] = '\0';
	}
	return (s);
}
/**
 * _strcmp - string comparation
 * @s1: first string to compare
 * @s2: second string
 * Return: diference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int differ = 0;
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		differ = s1[i] - s2[i];
			if (differ != 0)
				break;
	}
	if (differ == 0)
		return (0);
return (differ);
}

/**
 * _strcat - concatenate strings
 * @dest: string to be appended
 * @src: string to append
 * Return: string concatenated
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
