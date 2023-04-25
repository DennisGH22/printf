#ifndef main_h
#define main_h
int _putchar(char c);
int _puts(char *str);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int print_octal_number(unsigned int n);
int print_hex_number(unsigned int n, int uppercase);
int print_address(void *p);
int print_binary(unsigned int n);
int print_S(char *s);
int print_reverse(char *s);
char *rot13(char *s);
int _printf(const char *format, ...);
#endif