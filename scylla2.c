#include "functions_dec.h"

/**
 * shellprintenv - This is a customized printenv function
 *
 * Return: 0
 */
int shellprintenv(void)
{
	char *s = environ[0];
	int j = 0;

	while (s)
	{
		write(1, s, shellstrlen(s));
		write(1, "\n", 1);
		s = environ[++j];
	}
	return (0);
}

/**
 * shellstr_n_cmp - Compares two strings lexicographically, considering no more
 * than a specified count of characters, and returns an
 * integer based on the outcome.
 * @a1: initial string
 * @a2: Second string for comparison with the initial string
 * @n: Number of comparisons between a1 and a2
 * Return: <0 if a1 is less than a2, and 0 if it's equal, >0 if a1
 * greater than a2.
 * Description: It's an Src code file like GNU C library
 */
int shellstr_n_cmp(char *a1, char *a2, int n)
{
	char d3, d4;

	while (n--)
	{
		d3 = *a1++;
		d4 = *a2++;
		if (d3 == '\0' || d3 != d4)

			return (d3 > d4 ? 1 : (d3 < d4 ? -1 : 0));
	}
				return (0);
}

/**
 * shellgetenv - this is a custom getenv function.
 * @var: this is an environment variable
 *
 * Return: suceess (0)
 */
char *shellgetenv(char *var)
{
	int z = 0;

	for (z = 0; environ[z]; z++)
	{
		if (shellstr_n_cmp(environ[z], var, shellstrlen(var)) == 0)
			return (&environ[z][shellstrlen(var)]);
	}
	return (NULL);
}
