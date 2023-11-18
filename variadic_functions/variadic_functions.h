#ifndef HEADER_H
#define HEADER_H
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

void print_int(va_list *args);
void print_float(va_list *args);
void print_string(va_list *args);
void print_char(va_list *args);

typedef void (*print_handler)(va_list *);

typedef struct {
    char type_id;
    print_handler handler;
} TypeHandler;

/**
 * struct Formatter - Struct op
 *
 * @format_specifier: The operator
 * @format_printer: The function associated
 */

#endif
