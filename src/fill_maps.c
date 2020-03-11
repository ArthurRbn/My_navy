/*
** EPITECH PROJECT, 2020
** fill maps
** File description:
** fill maps
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void fill_map_enemy(base_infos_t *game)
{
    char array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int k = 0;
    int space = 1;

    game->enemys_map[0][0] = ' ';
    game->enemys_map[0][1] = '|';
    for (int i = 2; i < 17; ++i) {
        if (is_odd(space) == 2) {
            game->enemys_map[0][i] = ' ';
            ++space;
            continue;
        }
        game->enemys_map[0][i] = array[k];
        ++k;
        ++space;
    }
    fill_map_2_enemy(game);
    last_fill_enemy(game);
}

void fill_map_2_enemy(base_infos_t *game)
{
    game->enemys_map[1][0] = '-';
    game->enemys_map[1][1] = '+';
    for (int i = 2; i < 17; ++i)
        game->enemys_map[1][i] = '-';
}

void fill_map_2(base_infos_t *game)
{
    game->map[1][0] = '-';
    game->map[1][1] = '+';
    for (int i = 2; i < 17; ++i)
        game->map[1][i] = '-';
}

void last_fill_enemy(base_infos_t *game)
{
    char array[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    int k = 0;
    int space = 1;

    for (int a = 2; a < 10; ++a) {
        for (int i = 0; i < 17; ++i) {
            if (i == 0) {
                game->enemys_map[a][i] = array[k];
                continue;
            } if (i == 1) {
                game->enemys_map[a][i] = '|';
                continue;
            } if (is_odd(space) == 2) {
                game->enemys_map[a][i] = ' ';
                ++space;
                continue;
            } game->enemys_map[a][i] = '.';
            ++space;
        } space = 1;
        ++k;
    }
}

void fill_map(base_infos_t *game)
{
    char array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int k = 0;
    int space = 1;

    game->map[0][0] = ' ';
    game->map[0][1] = '|';
    for (int i = 2; i < 17; ++i) {
        if (is_odd(space) == 2) {
            game->map[0][i] = ' ';
            ++space;
            continue;
        }
        game->map[0][i] = array[k];
        ++k;
        ++space;
    }
    fill_map_2(game);
    last_fill(game);
}