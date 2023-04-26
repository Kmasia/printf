#include "main.h"

/**
 * get_width - derives printing width
 * @format: string to print arguments.
 * @i: arguments to print
 * @list: list of args
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int init_i;
	int width = 0;

	for (init_i = *i + 1; format[init_i] != '\0'; init_i++)
	{
		if (is_digit(format[init_i]))
		{
			width *= 10;
			width += format[init_i] - '0';
		}

		else if (format[init_i] == '*')
		{
			init_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = init_i - 1;

	return (width);
}

