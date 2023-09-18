#include "main.h"

/**
 * _printf - prints anything
 * @format: string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
int s = 0;
va_list ap;
char *ptr, *start;
params_t params = PARAMS_INIT;
va_start(ap, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (ptr = (char *)format; *ptr; ptr++)
{
init_params(&params, ap);
if (*ptr != '%')
{
s += _putchar(*ptr);
continue;
}
start = ptr;
ptr++;
while (get_flag(ptr, &params))
{
ptr++;
}
ptr = get_width(ptr, &params, ap);
ptr = get_precision(ptr, &params, ap);
if (get_modifier(ptr, &params))
ptr++;
if (!get_specifier(ptr))
s += print_from_to(start, ptr,
params.l_modifier || params.h_modifier ? ptr - 1 : 0);
else
s += get_print_func(ptr, ap, &params);
}
_putchar(BUF_FLUSH);
va_end(ap);
return (s);
}
