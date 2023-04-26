#include "main.h"

/**
 * get_precision - function for precise printing
 * @format: Formatted string
 * @i: arguments.
 * @list: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int init_i = *i + 1;
	int prec = -1;

	if (format[init_i] != '.')
		return (prec);

	prec = 0;

	for (init_i += 1; format[init_i] != '\0'; init_i++)
	{
		if (is_digit(format[init_i]))
		{
			prec *= 10;
			prec += format[init_i] - '0';
		}
		else if (format[init_i] == '*')
		{
			init_i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = init_i - 1;

	return (prec);
}

