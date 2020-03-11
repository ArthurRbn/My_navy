/*
** EPITECH PROJECT, 2019
** disp_stdarg
** File description:
** display std arguments
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

int flags(int c)
{
    int i = 0;
    char param[] = {'d', 'c', 's'};
    if (c == 105)
        return (0);
    while (c != param[i]) {
        ++i;
    }
    return (i);
}

void integr(va_list arg)
{
    my_put_nbr(va_arg(arg, int));
}

void charr(va_list arg)
{
    my_putchar(va_arg(arg, int));
}

void str(va_list arg)
{
    my_putstr(va_arg(arg, char *));
}

int my_printf(const char *format, ...)
{
    int flg = 2;
    va_list arg;
    void (*fparam[])(va_list arg) = {*integr, *charr, *str};
    va_start(arg, 0);
    for (int i = 0; format[i] != '\0'; ++i) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else if (format[i] == '%' && format[i + 1] == '%') {
            my_putchar('%');
            ++i;
        } else {
            ++i;
            flg = flags(format[i]);
            fparam[flg](arg);
        }
    }
    return (0);
}