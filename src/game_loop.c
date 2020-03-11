/*
** EPITECH PROJECT, 2020
** loop
** File description:
** lopp
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int game_loop(base_infos_t *game)
{
    game->state = 0;

    while (game->state == 0) {
        my_putstr("attack:   ");
        if (read_input(game) != 0) {
            my_putstr("wrong position\n");
            continue;
        }
        my_putstr(game->attack_position);
        my_putstr(": hit\n");
    }
}