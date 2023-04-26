#include "main.h"

/**
 * get_size - Casts arguments to calculated size
 * @format: string formatted for printing args
 * @i: List of printing  args
 * Return: size
 */

int get_size(const char *format, int *i)
{
	int init_i;
	int size;

	init_i = *i + 1;
	size = 0;

	if (format[init_i] == 'l')
		size = S_LONG;

	else if (format[init_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = init_i - 1;
	else
		*i = init_i;

	return (size);
}
