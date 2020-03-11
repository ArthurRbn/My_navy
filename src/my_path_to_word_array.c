/*
** EPITECH PROJECT, 2020
** my_path
** File description:
** my_path
*/

#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>

int count_words2(char *str)
{
    int count_words = 1;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == ':') {
            ++count_words;
        }
    }
    return (count_words);
}

void separate_words2(char *str, struct DT *var)
{
    var->counter = 0;

    for (; str[var->i] != '\0'; var->i++) {
        if (str[var->i] == ':')
            break;
        var->counter++;
    }
}

char **my_malloc_tab2(int count_words, char *str, struct DT *var)
{
    char **tab = malloc(sizeof(char *) * (count_words + 1));
    tab[count_words] = NULL;
    var->i = 0;

    for (int a = 0; a != count_words; ++a) {
        separate_words2(str, var);
        tab[a] = malloc(sizeof(char) * (var->counter + 1));
        tab[a][var->counter] = 0;
        var->i++;
    }
    return (tab);
}

char **my_path_to_word_array(char *str)
{
    struct DT *var = malloc(sizeof(struct DT));
    int count = count_words2(str);
    char **tab = my_malloc_tab2(count, str, var);
    int k = 0;
    int a = 0;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == ':') {
            ++a;
            k = 0;
            ++i;
        }
        tab[a][k] = str[i];
        ++k;
    }
    return (tab);
}