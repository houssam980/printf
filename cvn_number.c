#include "main.h"

/**
 * print_hex - prints unsigned hex
 * @ap:argument
 * @params: parameters
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
unsigned long ln;
int c = 0;
char *str;

if (params->l_modifier)
ln = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
ln = (unsigned short int)va_arg(ap, unsigned int);
else
ln = (unsigned int)va_arg(ap, unsigned int);

str = convert(ln, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && ln)
{
*--str = 'x';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * print_HEX - prints hex numbers UPPER
 * @ap:argument
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
unsigned long ln_1;
int c = 0;
char *str;

if (params->l_modifier)
ln_1 = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
ln_1 = (unsigned short int)va_arg(ap, unsigned int);
else
ln_1 = (unsigned int)va_arg(ap, unsigned int);

str = convert(ln_1, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && ln_1)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}
/**
 * print_binary - prints binary
 * @ap: argument
 * @params: parameters
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
unsigned int num = va_arg(ap, unsigned int);
char *str = convert(num, 2, CONVERT_UNSIGNED, params);
int crt = 0;

if (params->hashtag_flag && num)
*--str = '0';
params->unsign = 1;
return (crt += print_number(str, params));
}
/**
 * print_octal - prints octal numbers
 * @ap:argument
 * @params:parameters
 * Return: bytes
 */
int print_octal(va_list ap, params_t *params)
{
unsigned long l;
char *str;
int ctr = 0;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
*--str = '0';
params->unsign = 1;
return (ctr += print_number(str, params));
}

