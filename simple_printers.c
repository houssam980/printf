#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: sta address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int su = 0;

	while (start <= stop)
	{
		if (start != except)
			su += _putchar(*start);
		start++;
	}
	return (su);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int len, su = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			su += _putchar(*str);
	}
	return (su);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int r, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	r = 0;
	index = 0;
	while (a[r])
	{
		if ((a[r] >= 'A' && a[r] <= 'Z')
		    || (a[r] >= 'a' && a[r] <= 'z'))
		{
			index = a[r] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[r]);
		r++;
	}
	return (count);
}


