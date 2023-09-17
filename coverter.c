#include "main.h"

/**
 * print_hex - prints hex numbers
 * @ap: the argument
 * @params: the parameters
 * Return: return bytes prints
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
 * print_HEX - prints unsigned hex UPPER CASE
 * @ap: the argument
 * @params:parameters
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
unsigned long ln_2;
int c = 0;
char *str;

if (params->l_modifier)
ln_2 = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
ln_2 = (unsigned short int)va_arg(ap, unsigned int);
else
ln_2 = (unsigned int)va_arg(ap, unsigned int);

str = convert(ln_2, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && ln_2)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}
/**
 * print_binary - prints binary 
 * @ap: the argument pointer
 * @params: parameters
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
unsigned int num = va_arg(ap, unsigned int);
char *str = convert(num, 2, CONVERT_UNSIGNED, params);
int c = 0;

if (params->hashtag_flag && num)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * print_octal - prints octal
 * @ap: the argument
 * @params:parameters
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
unsigned long ln_3;
char *str;
int c = 0;

if (params->l_modifier)
ln_3 = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
ln_3 = (unsigned short int)va_arg(ap, unsigned int);
else
ln_3 = (unsigned int)va_arg(ap, unsigned int);
str = convert(ln_3, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && ln_3)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}

