#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@len: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int len)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < len)
	{
		j = i;
		while (j < len)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@len: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int len)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < len)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < len)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@str: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
