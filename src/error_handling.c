/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int error_handling_nbr(char **tab, base_infos_t *game)
{
    if (my_getnbr(tab[0]) != game->nrml)
        return (84);
    game->nrml++;
    return (0);
}

int error_handling_length(char **tab)
{
    int value = 0;

    if (tab[1][0] == tab[2][0])
        value = error_for_x(tab);
    else
        value = error_for_y(tab);
    return (value);
}

int check_letter(char *file)
{
    if (file[1] != ':')
        return (84);
    if (file[4] != ':')
        return (84);

    for (int i = 0; file[i]; ++i) {
        if (file[i] > 72)
            return (84);
        if (file[i] < 49)
            return (84);
    }
    return (0);
}

int connect(char **file, base_infos_t *game)
{
    int fd = 0;

    if (game->version == HOST)
        fd = open(file[1], O_RDONLY);
    else if (game->version == CLIENT)
        fd = open(file[2], O_RDONLY);
    return (fd);
}

int g_error(char **file, base_infos_t *game, int ac)
{
    char *buff;
    game->nrml = 2;
    char **tab;
    int fd = 0;

    if (init_version(game, file, ac) == 84)
        return (84);
    fd = connect(file, game);
    if (fd == -1)
        return (84);
    for (int i = 0; i < 4; ++i) {
        buff = get_next_line(fd);
        if (my_strlen(buff) == 0 || my_strlen(buff) > 7 ||
        check_letter(buff) == 84)
            return (84);
        tab = my_path_to_word_array(buff);
        if (error_handling_nbr(tab, game) == 84 ||
        error_handling_length(tab) == 84)
            return (84);
    }
    return (0);
}