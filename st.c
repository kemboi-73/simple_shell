#include "shell.h"
/**
 * is_in_str - checks whether given character is in a given string
 * @str: string
 * @c: character
 *
 * Return: 1 if c is in str. 0 Otherwise
 */
int is_in_str(const char *str, char c)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}

	return (0);
}

/**
* _strcmp - compares 2 strings
* @s1: first string
* @s2: second string
*
* Description: works exactly like strcmp from <string.h>
*
* Return: -ve integer, 0 or +ve integer if s1 is less than,
* equal to or greater than s2
*/
int _strcmp(const char *s1, const char *s2)
{
	int diff = 0;

	while (diff == 0)
	{
		diff = *s1 - *s2;
		/* break if one of the strings is empty */
		if (*s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	return (diff);
}
