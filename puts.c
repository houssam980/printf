#include "main.h"

/**
 * _puts - prints a
 * @str: string
 * Return: nothing
 */
int _puts(char *str)
{
char *ch = str;
while (*str)
_putchar(*str++);
return (str - ch);
}

/**
 * _putchar - writes a character
 * @c:character
 * Return: On success 1 On error, -1 returned 
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
