/*
** EPITECH PROJECT, 2020
** map handling
** File description:
** map handling
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

int error_for_x(char **tab)
{
    int comp = my_getnbr(tab[0]);
    int a = my_getnbr(tab[1]);
    int b = my_getnbr(tab[2]);

    if (a > b)
        return (84);

    if (((b - a) + 1) != comp)
        return (84);
    return (0);
}

int error_for_y(char **tab)
{
    int counter = 1;
    int comp = my_getnbr(tab[0]);
    int a = tab[1][0];
    int b = tab[2][0];

    if (a > b)
        return (84);
    for (int i = a; i != b; ++i) {
        ++counter;
    }
    if (counter != comp)
        return (84);
    return (0);
}

void create_map_enemy(base_infos_t *game)
{
    malloc_map_enemy(game);
    fill_map_enemy(game);
}

void last_fill(base_infos_t *game)
{
    char array[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    int k = 0;
    int space = 1;

    for (int a = 2; a < 10; ++a) {
        for (int i = 0; i < 17; ++i) {
            if (i == 0) {
                game->map[a][i] = array[k];
                continue;
            } if (i == 1) {
                game->map[a][i] = '|';
                continue;
            } if (is_odd(space) == 2) {
                game->map[a][i] = ' ';
                ++space;
                continue;
            } game->map[a][i] = '.';
            ++space;
        } space = 1;
        ++k;
    }
}

void fill_boat(base_infos_t *game, char **tab)
{
    int counter_x;
    int counter_y;
    int index_1 = 1;
    int index_2 = 0;

    for (int nb_loop = 2; nb_loop > 0; --nb_loop) {
        counter_x = count_x(game, tab, index_1, index_2);
        ++index_2;
        counter_y = count_y(game, tab, index_1, index_2);
        ++index_1;
        index_2 = 0;
        game->map[counter_y][counter_x] = tab[0][0];
        if (game->manage_loop > 0 && nb_loop == 1) {
            if (tab[1][0] == tab[2][0])
                fill_interval_y(game, tab, counter_x, counter_y);
            else
                fill_interval_x(game, tab, counter_x, counter_y);
        } counter_x = 2;
        counter_y = 2;
    }
}