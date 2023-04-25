#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string to stdout.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
*/

int _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}

/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 *
 * Return: The number of digits printed.
*/

int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * print_unsigned_number - Prints an unsigned integer.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
*/

int print_unsigned_number(unsigned int n)
{
	unsigned int num = n;
	int count = 0;

	if (num / 10)
		count += print_unsigned_number(num / 10);

	_putchar(num % 10 + '0');
	count++;

	return (count);
}

/**
 * print_octal_number - Prints the octal representation of the integer.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
*/

int print_octal_number(unsigned int n)
{
	unsigned int num = n;
	int count = 0, i = 0;
	char octal[100];

	while (num != 0)
	{
		octal[i] = num % 8 + '0';
		num /= 8;
		i++;
	}

	if (i == 0)
		octal[i++] = '0';

	for (i--; i >= 0; i--)
	{
		_putchar(octal[i]);
		count++;
	}

	return (count);
}

/**
 * print_hex_number - Prints a hexadecimal representation of the integer.
 * @n: The integer to be printed.
 * @uppercase: Letters to be printed.
 *
 * Return: The number of characters printed.
*/

int print_hex_number(unsigned int n, int uppercase)
{
	unsigned int num = n;
	int count = 0, i = 0;
	char hex[100], base = uppercase ? 'A' : 'a';

	while (num != 0)
	{
		int digit = num % 16;
		if (digit < 10)
			hex[i] = digit + '0';
		else
			hex[i] = digit - 10 + base;
		num /= 16;
		i++;
	}

	if (i == 0)
		hex[i++] = '0';

	for (i--; i >= 0; i--)
	{
		_putchar(hex[i]);
		count++;
	}

	return (count);
}

/**
 * print_address - Prints the address of a pointer.
 * @p: The pointer of address to be printed.
 *
 * Return: The number of characters printed.
*/

int print_address(void *p)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, 20, "%p", (void *)p);
	return (write(1, buffer, len));
}

/**
 * _printf - Produces output according to a format.
 * @format: The character string.
 *
 * Return: The number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd': case 'i':
					count += print_number(va_arg(args, int));
					break;
				case 'u':
					count += print_unsigned_number(va_arg(args, unsigned int));
					break;
				case 'o':
					count += print_octal_number(va_arg(args, unsigned int));
					break;
				case 'x': case 'X':
					count += print_hex_number(va_arg(args, unsigned int), *format == 'X');
					break;
				case 'p':
					count += print_address(va_arg(args, void *));
					break;
				default:
					count += _putchar('%') + _putchar(*format);
			}
		}
		else
			count += _putchar(*format);
		format++;
	}
	va_end(args);

	return (count);
}
