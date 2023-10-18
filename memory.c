#include "shell.h"

/**
 * dfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int dfree(void **ptr)
{
	if (ptr && *ptr)
	{
		dfree(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
