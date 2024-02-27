#include "functions_dec.h"

/**
 **shellstrcat(char *dest, char *src)- a specialized function
 * that combines two strings.
 *@dest: Char input
 *@src: Char input
 *
 * Return: 0 Always.
 */

char *shellstrcat(char *dest, char *src)
{
	int st = 0;

	int size = shellstrlen(dest);

	while (src[st] != '\0')
	{
		dest[size] = src[st];
		size++;
		st++;
	}
	dest[size] = '\0';
	return (dest);
}

/**
 * shellstrcmp- a specialized function that compares two strings.
 * @str1: String one
 * @str2: String two that compares it to string one.
 *
 * Return: <0 if str1 is less than str2, and returns  0 if they are equal,
 * and returns >0 if str1 is greater than str2.
 */
int shellstrcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
	if (*str1 == '\0')
	{
	return (0);
	}
	str1++;
	str2++;
	}
	return (*str1 - *str2);
}

/**
 * char *shellstrcpy- duplicates a string
 *@dest: Handles the new duplicated string
 *@src: This is the initial string to duplicate
 *
 * Return: Always 0.
 */
char *shellstrcpy(char *dest, char *src)
{
	int size;
	int cd;

	size = shellstrlen(src);

	for (cd = 0; cd < size; cd++)
	{
		dest[cd] = src[cd];
	}
	dest[cd] = '\0';

	return (dest);
}

/**
 * shellstrlen(char *s)- a function that provides the size of a string.
 *@s: a glyph
 *
 * Return: Always 0.
 */

int shellstrlen(char *s)
{
	int cd = 0;

	while (s[cd] != '\0')
	{
		cd++;
		}
	return (cd);
}

/**
 * *shellstrdup - duplicates the provided string.
 * @string: entered string
 *
 * Return: *pointer to the duplicated string or  NULL (if Error)
 */
char *shellstrdup(char *string)
{
	char *duplicate;
	unsigned int cd = 0, size = 0;

	if (string == NULL)
		return (NULL);

	while (string[size])
		size++;

	duplicate = malloc(sizeof(char) * (size + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[cd] = string[cd]) != '\0')
		cd++;

	return (duplicate);
}
