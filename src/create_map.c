/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void print_map_with_boat(base_infos_t *game)
{
    my_putstr("my positions:\n");
    for (int i = 0; i <= 9; ++i) {
        my_putstr(game->map[i]);
        my_putstr("\n");
    }
}

void print_map_enemy(base_infos_t *game)
{
    my_putstr("enemy's positions:\n");
    for (int i = 0; i <= 9; ++i) {
        my_putstr(game->enemys_map[i]);
        my_putstr("\n");
    }
}

int is_odd(int nbr)
{
    if ((nbr % 2) == 0)
        return (2);
    else if ((nbr % 2) == 1)
        return (1);
    return (2);
}

void malloc_map_enemy(base_infos_t *game)
{
    game->enemys_map = malloc(sizeof(char *) * 11);
    game->enemys_map[10] = NULL;

    for (int i = 0; i < 11; ++i) {
        game->enemys_map[i] = malloc(sizeof(char) * 18);
        game->enemys_map[i][17] = 0;
    }
}

void malloc_map(base_infos_t *game)
{
    game->map = malloc(sizeof(char *) * 11);
    game->map[10] = NULL;

    for (int i = 0; i < 11; ++i) {
        game->map[i] = malloc(sizeof(char) * 18);
        game->map[i][17] = 0;
    }
}