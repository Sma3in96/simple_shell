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
char *_strtok(char string[], const char *del)
{
	static char *splitted, *str_end;
	char *sstart;
	unsigned int i; 
	unsigned int bo;

	if (string != NULL)
	{
		if (coom(string, del))
			return (NULL);
		splitted = string;
		i = _strlen(string);
		str_end = &string[i];
	}
	sstart = splitted;
	if (sstart == str_end)
		return (NULL);

	for (bo = 0; *splitted; splitted++)
	{
		if (splitted != sstart)
			if (*splitted && *(splitted - 1) == '\0')
				break;

		for (i = 0; del[i]; i++)
		{
			if (*splitted == del[i])
			{
				*splitted = '\0';
				if (splitted == sstart)
					sstart++;
				break;
			}
		}
		if (bo == 0 && *splitted)
		{
			bo = 1;
		}
	}
	if (bo == 0)
	{
		return (NULL);
	}
	return (sstart);
}
