#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int length = 0;
	char *result;

	if (s == NULL)
		return (NULL);
	while (*s++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--s;
	return (result);
}

/**
 * _puts - prints an input string
 * @s: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *s)
{
	int k = 0;

	if (!s)
		return;
	while (s[k] != '\0')
	{
		_putchar(s[k]);
		k++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buff, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buff[j++] = c;
	return (1);
}
