/*
** EPITECH PROJECT, 2019
** get number
** File description:
** get number
*/
#include <stdio.h>
#include "include/my.h"

int my_getnbr(char *src)
{
    long res = 0;
    int mult = 1;
    int lon = my_strlen(src);

    for (int i = lon - 1; i >= 0; --i) {
        if (src[i] == '-') {
            res = res * -1;
        } else {
            res = res + ((src[i] - 48) * mult);
            mult = mult * 10;
        }
    }
    return (res);
}