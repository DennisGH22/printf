#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_string - prints a string
 * @args: list of arguments
 * @buffer: buffer to print to
 * @pos: current position in buffer
 * @flags: flags to modify behavior
 * @width: minimum field width
 * @precision: maximum string length to be printed
 *
 * Return: number of characters printed
 */
int print_string(va_list args, char *buffer, int *pos, int flags, int width, int precision)
{
    char *str = va_arg(args, char *);
    int len = 0, pad = 0, i;

    if (!str)
        str = "(null)";

    len = _strlen(str);

    if (precision >= 0 && precision < len)
        len = precision;

    pad = width - len;

    if (flags & FLAG_MINUS)
    {
        for (i = 0; i < len; i++)
            _putchar(buffer, pos, str[i]);

        while (pad-- > 0)
            _putchar(buffer, pos, ' ');
    }
    else
    {
        char fill = ' ';

        if (flags & FLAG_ZERO)
            fill = '0';

        while (pad-- > 0)
            _putchar(buffer, pos, fill);

        for (i = 0; i < len; i++)
            _putchar(buffer, pos, str[i]);
    }

    return len;
}
