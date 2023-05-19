#include <unistd.h>

/**
 * _putchar - writes the charracter c to stdoout
 * @c: The characteer to print.
 *
 * Return: On successs 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

