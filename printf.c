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
 * print_octal_number - Prints the octal of the integer.
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
 * print_hex_number - Prints a hexadecimal of the integer.
 * @n: The integer to be printed.
 * @uppercase: Letters to be printed.
 *
 * Return: The number of characters printed.
*/

int print_hex_number(unsigned int n, int uppercase)
{
	unsigned int num = n;
	int count = 0, i = 0, digit;
	char hex[100], base = uppercase ? 'A' : 'a';

	while (num != 0)
	{
		digit = num % 16;
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
 * print_binary - Converts the integer to binary.
 * @n: The integer to be printed as binary.
 *
 * Return: The number of digits printed.
*/

int print_binary(unsigned int n)
{
    int count = 0;

    if (n > 1)
        count += print_binary(n >> 1);
    _putchar((n & 1) + '0');
    count++;

    return (count);
}

/**
 * print_S - Prints a string.
 * @s: The string to be printed.
 *
 * Return: The number of characters printed.
*/

int print_S(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			if (*s < 16)
			{
				_putchar('0');
				count++;
			}
			count += print_hex_number(*s, 1);
		}
		else
		{
			_putchar(*s);
			count++;
		}
		s++;
	}
	return (count);
}

/**
 * print_reverse - Prints a string in reverse.
 * @s: The string printed in reverse.
 *
 * Return: The number of characters printed.
*/

int print_reverse(char *s)
{
	int i, len = 0;

	while (s[len])
		len++;

	for (i = len - 1; i >= 0; i--)
		_putchar(s[i]);

	return (len);
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
                case 'b':
                    count += print_binary(va_arg(args, unsigned int));
                    break;
				case 'S':
					count += print_S(va_arg(args, char *));
					break;
				case 'r':
					count += print_reverse(va_arg(args, char *));
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
