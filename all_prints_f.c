#include "main.h"

/**
 * print_from_to - prints a range of char
 * @start: start
 * @stop: stop
 * @except: except
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
int sum = 0;
while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}
return (sum);
}

/**
 * print_rev - string in reverse
 * @ap: string
 * @params: parameters
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
int len, sum = 0;
char *str = va_arg(ap, char *);
(void)params;

if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str--)
sum += _putchar(*str);
}
return (sum);
}

/**
 * print_rot13 - prints in rot13
 * @ap: string
 * @params:parameters
 * Return: number bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
int i, ind;
int counter = 0;
char arr[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(ap, char *);
(void)params;

i = 0;
ind = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
ind = a[i] - 65;
counter += _putchar(arr[ind]);
}
else
counter += _putchar(a[i]);
i++;
}
return (counter);
}


