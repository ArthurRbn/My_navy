/*
** EPITECH PROJECT, 2020
** shot
** File description:
** shot
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int put_x_or_o(base_infos_t *game)
{
    game->enemy_x *= 2;
    game->enemy_y += 1;

    if ((game->map[game->enemy_y][game->enemy_x] != '.') &&
    (game->map[game->enemy_y][game->enemy_x] != ' ') &&
    game->map[game->enemy_y][game->enemy_x] != 'x' &&
    game->map[game->enemy_y][game->enemy_x] != 'o') {
        game->map[game->enemy_y][game->enemy_x] = 'x';
        game->counter_win_enemy++;
        return (1);
    }
    else if (game->map[game->enemy_y][game->enemy_x] == '.') {
        game->map[game->enemy_y][game->enemy_x] = 'o';
        return (0);
    }
    return (0);
}

void print_on_enemy(base_infos_t *game, int touched)
{
    int attack_x = game->attack_position[0] - 64;
    int attack_y = game->attack_position[1] - 48;

    attack_x *= 2;
    attack_y += 1;
    if (touched == 1) {
        game->enemys_map[attack_y][attack_x] = 'x';
        game->counter_win++;
    } else if (touched == 0 && game->enemys_map[attack_y][attack_x] != 'x' &&
    game->enemys_map[attack_y][attack_x] != 'o')
        game->enemys_map[attack_y][attack_x] = 'o';
}