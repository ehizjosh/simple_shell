#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, otherwise 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the character to be checked
 * @delim: the delimeter string
 *
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: the character to input
 *
 * Return: 1 if c is alphabetic, otherwise 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int j, sign = 1, parsing_flag = 0, output;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && parsing_flag != 2; j++)
	{
		if (s[j] == '-')
		{
			sign *= -1;
		}

		if (s[j] >= '0' && s[j] <= '9')
		{
			parsing_flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (parsing_flag == 1)
		{
			parsing_flag = 2;
		}
	}

	if (sign == -1)
	{
		output = -result;
	}
	else
	{
		output = result;
	}

	return (output);
}
