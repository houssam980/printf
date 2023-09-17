#include "main.h"

/**
 * _put_s - prints an str
 * @str: the string to print
 * Return: nothing to return
 */
int _put_s(char *str)
{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}

/**
 * _putchar - write char
 * @c: The character 
 * Return: On success 1.
 * On error, -1 is returned, and error displayed
 */
int _putchar(int c)
{
static int lp;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || lp >= OUTPUT_BUF_SIZE)
{
write(1, buf, lp);
lp = 0;
}
if (c != BUF_FLUSH)
buf[lp++] = c;
return (1);
}
