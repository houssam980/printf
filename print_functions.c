#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, su = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		su += _putchar(ch);
	while (pad++ < params->width)
		su += _putchar(pad_char);
	if (!params->minus_flag)
		su += _putchar(ch);
	return (su);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list ap, params_t *params)
{
	long v;

	if (params->l_modifier)
		v = va_arg(ap, long);
	else if (params->h_modifier)
		v = (short int)va_arg(ap, int);
	else
		v = (int)va_arg(ap, int);
	return (print_number(convert(v, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, su = 0, r = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (r = 0; r < pad; r++)
				su += _putchar(*str++);
		else
			su += _puts(str);
	}
	while (j++ < params->width)
		su += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (r = 0; r < pad; r++)
				su += _putchar(*str++);
		else
			su += _puts(str);
	}
	return (su);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int su = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			su += _putchar('\\');
			su += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				su += _putchar('0');
			su += _puts(hex);
		}
		else
		{
			su += _putchar(*str);
		}
	}
	return (su);
}

