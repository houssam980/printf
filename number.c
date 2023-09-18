#include "main.h"

/**
 * convert - converter functions
 * @num: number
 * @base: base
 * @flags: the argument
 * @params: paramater 
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long nm = num;
(void)params;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
nm = -num;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
*--ptr = array[nm % base];
nm /= base;
} while (nm != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * print_unsigned - prints int numbers
 * @ap: argument
 * @params: parameters
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
unsigned long ln;

if (params->l_modifier)
ln = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
ln = (unsigned short int)va_arg(ap, unsigned int);
else
ln = (unsigned int)va_arg(ap, unsigned int);
params->unsign = 1;
return (print_number(convert(ln, 10, CONVERT_UNSIGNED, params), params));
}


/**
 * print_address - print address
 * @ap: argument
 * @params: parameters
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
unsigned long int nm_1 = va_arg(ap, unsigned long int);
char *str;
if (!nm_1)
return (_puts("(nil)"));
str = convert(nm_1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--str = 'x';
*--str = '0';
return (print_number(str, params));
}


