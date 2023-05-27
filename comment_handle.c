#include "shell.h"
/**
 * the_coment -removes comments from the 
 * @in: the strings input
 * Return: comments thad does not have input
 */
char *the_coment(char *in)
{
	int i, j;
	char *out = in;

	for (i = 0, j = 0; in[i] != '\0'; i++)
	{
		if (in[i] == '#' && (i == 0 || in[i - 1] == '\n' ||
							 in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';'))
		{
			while (in[i] != '\n' && in[i] != '\0')
				i++;
		}
		else
		{
			out[j++] = in[i];
		}
	}

	out[j] = '\0';

	return (out);
}
