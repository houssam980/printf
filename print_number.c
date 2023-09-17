#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int r = 0;

	while (*s++)
		r++;
	return (r);
}

/**
 * print_number - prints a number with options
 * @str: base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int r = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		r--;
	}
	if (params->precision != UINT_MAX)
		while (r++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, r = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		r++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (r++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, r = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && r < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), r++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), r++;
	n += _puts(str);
	while (r++ < params->width)
		n += _putchar(pad_char);
	return (n);
}

