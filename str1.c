#include "main.h"
/**
 * _strstr -  finds the first occurrence of the substring
 * @haystack: string
 * @needle: substring
 *
 * Return: pointer
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 1;

	while (*(haystack + i) != '\0')
	{
		if (*(haystack + i) == *needle)
		{
			while (*(needle + j) != '\0')
			{
				if (*(needle + j) != *(haystack + i + j))
				{
					break;
				}
				j++;
			}
			if (*(needle + j) == '\0')
			{
				return (haystack + i);
			}
			j = 1;
		}
		i++;
	}
	return ('\0');
}
/**
 * _strcat - concatenates two strings
 * @dest: dest
 * @src : source
 *
 * Return: a pointer
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * _strncpy - copy a string
 * @dest: dest
 * @src: source
 * @n: int
 *
 * Return: pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	while (*(src + j) && j < n)
	{
	*(dest + j) = *(src + j);
	j++;
	}
	for ( ; j < n; j++)
		dest[j] = '\0';
	return (dest);
}
/**
 * _strcmp - cmp 2 strings
 * @s1: str 1
 * @s2: str 2
 *
 * Return: +15 -15 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (j == 0)
	{
		if (!s1[i] && !s2[i])
			break;
		j = s1[i] - s2[i];
		i++;
	}
	return (j);
}
/**
 * _strcpy - copy string to another
 * @dest: new string
 * @src: source string
 *
 * Return: pointer on new string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = *(src + i);
	return (dest);
}
