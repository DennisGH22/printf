#ifndef MAIN_H
#define MAIN_H
int _putchar(char c);
int _puts(char *str);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int print_octal_number(unsigned int n);
int print_hex_number(unsigned int n, int uppercase);
int print_address(void *p);
int _printf(const char *format, ...);
#endif