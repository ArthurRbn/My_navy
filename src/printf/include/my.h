/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
char *my_revstr(char *str);
int my_getnbr(char *src);
int my_printf(const char *format, ...);

#endif //MY_H
