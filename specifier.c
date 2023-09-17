#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_addr},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
int _main_lp = 0;

while (specifiers[_main_lp].specifier)
{
if (*s == specifiers[_main_lp].specifier[0])
{
return (specifiers[_main_lp].f);
}
_main_lp++;
}
return (NULL);
}

/**
 * get_print_func - format finder
 * @s:string
 * @ap: argument 
 * @params: parameters
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - flag finder
 * @s:string
 * @params: parameters
 * Return: if flag was excists
 */
int get_flag(char *s, params_t *params)
{
int lp_2 = 0;
switch (*s)
{
case '+':
lp_2 = params->plus_flag = 1;
break;
case ' ':
lp_2 = params->space_flag = 1;
break;
case '#':
lp_2 = params->hashtag_flag = 1;
break;
case '-':
lp_2 = params->minus_flag = 1;
break;
case '0':
lp_2 = params->zero_flag = 1;
break;
}
return (lp_2);
}

/**
 * get_modifier - find func modi
 * @s: string
 * @params: parameters
 * Return: if modifier was excists
 */
int get_modifier(char *s, params_t *params)
{
int lp_3 = 0;
switch (*s)
{
case 'h':
lp_3 = params->h_modifier = 1;
break;
case 'l':
lp_3 = params->l_modifier = 1;
break;
}
return (lp_3);
}

/**
 * get_width - width string
 * @s: string
 * @params:parameters
 * @ap: the argument 
 * Return: new ptr
 */
char *get_width(char *s, params_t *params, va_list ap)
{
int dy = 0;

if (*s == '*')
{
dy = va_arg(ap, int);
s++;
}
else
{
while (_isdigit(*s))
dy = dy * 10 + (*s++ - '0');
}
params->width = dy;
return (s);
}

