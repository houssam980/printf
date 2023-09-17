#include "main.h"

/**
 * _printf - prints anything
 * @format: the format of a string
 * Return: bytes
 */
int _printf(const char *format, ...)
{
int su = 0;
va_list ap;
char *poi, *start;
params_t params = PARAMS_INIT;

	va_start(ap, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (poi = (char *)format; *poi; poi++)
{
init_params(&params, ap);
if (*poi != '%')
{
su += _putchar(*poi);
continue;
}
start = poi;
poi++;
while (get_flag(poi, &params)) /* while char at p is flag char */
{
poi++; /* next char */
}
poi = get_width(poi, &params, ap);
poi = get_precision(poi, &params, ap);
if (get_modifier(poi, &params))
poi++;
if (!get_specifier(poi))
su += print_from_to(start, poi,
params.l_modifier || params.h_modifier ? poi - 1 : 0);
else
su += get_print_func(poi, ap, &params);
}
_putchar(BUF_FLUSH);
va_end(ap);
return (su);
}
