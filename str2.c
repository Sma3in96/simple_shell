#include "main.h"
/**
 * _strdup - duplication a string
 * @str: string
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	int j = 0, i;
	char *p;

	if (str == NULL)
		return (NULL);
	while (*(str + j))
	{
		j++;
	}
	j++;
	p = (char *)malloc(j * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
	{
		p[i] = *(str + i);
	}
	return (p);
}
/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * coom - string cmp
 * @str: given string
 * @delim: delimiter
 *
 * Return: 1.
 */
int coom(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string.
 * @str: given string
 * @delim: delimiter to the string
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (coom(str, delim))
			return (NULL);
		splitted = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;

		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}
