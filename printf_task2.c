#include "main.h"

/**
 * print_unsigned - this will display an unsiged value
 * @types: list all the arguments
 * @buffer: a buffer array tha manages print
 * @width: it will allocate the width
 * @size: it determines the size
 * @flags: it calculates working flags
 * @precision: specifies precision
 * Return: will return the number of unsigned values
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num1 = va_arg(types, unsigned long int);

	num1 = convert_size_unsgnd(num1, size);
	if (num1 == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[a--] = (num1 % 10) + '0';
		num1 /= 10;
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
/**
 * print_octal - oprtical number is used to print unsigned value
 * @types: list all the arguments
 * @buffer: a buffer array tha manages print
 * @width: it will allocate the width
 * @size: it determines the size
 * @flags: it calculates working flags
 * @precision: specifies precision
 * Return: will return the number of unsigned values
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);
	unsigned long int init_num = value;

	UNUSED(width);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (value > 0)
	{
		buffer[a--] = (value % 8) + '0';
		value /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - hexadecimal notation is used to print an unsigned value
 * @types: list all the arguments
 * @buffer: a buffer array tha manages print
 * @width: it will allocate the width
 * @size: it determines the size
 * @flags: it calculates working flags
 * @precision: specifies precision
 * Return: will return the number of unsigned values
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - upper hexadecimal notation
 * is used to print unsigned value
 * @types: list all the arguments
 * @buffer: a buffer array tha manages print
 * @width: it will allocate the width
 * @size: it determines the size
 * @flags: it calculates working flags
 * @precision: specifies precision
 * Return: will return the number of unsigned value
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 * print_hexa - this will print the hexadecimal in lower or upper
 * @map_to: the array of values the number is mapped to
 * @types: list all the arguments
 * @buffer: a buffer array tha manages print
 * @width: it will allocate the width
 * @size: it determines the size
 * @flags: it calculates working flags
 * @flag_ch: it calculates working flags
 * @precision: specifies precision
 * Return: will return the number of unsigned values
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int value = va_arg(types, unsigned long int);
	unsigned long int init_num = value;

	UNUSED(width);

	value = convert_size_unsgnd(value, size);

	if (value == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (value > 0)
	{
		buffer[b--] = map_to[value % 16];
		value /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[b--] = flag_ch;
		buffer[b--] = '0';
	}
	b++;
	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}
