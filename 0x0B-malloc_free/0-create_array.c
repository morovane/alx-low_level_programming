#include "main.h"
#include <stdlib.h>

/**
 * create_array - function that creates an array of chars
 * @size: parametre
 * @c: the characters
 * Return: a
 */
char *create_array(unsigned int size, char c)
{
	char *a = malloc(size * sizeof(char));
	unsigned int i = 0;

	while (i < size)
	{
		a[i] = c;
		i++;
	}

	return (a);
}
