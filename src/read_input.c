/*
** EPITECH PROJECT, 2020
** read
** File description:
** read
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void convert_digit_into_x_y(base_infos_t *game)
{
    game->enemy_x = 2;
    game->enemy_y = 1;
    char *array[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    char *temp = malloc(sizeof(char) * 2);
    char *temp2 = malloc(sizeof(char) * 2);
    temp2[1] = 0;
    temp[1] = 0;
    temp2[0] = game->attack_position[1];
    temp[0] = game->attack_position[0];

    for (int i = 0; i < 8; ++i) {
        if (my_strcmp(array[i], temp) != 0)
            continue;
        else {
            game->enemy_x = game->enemy_x + i;
            break;
        }
    }
    game->enemy_y = game->enemy_y + my_getnbr(temp2);
}

int read_input(base_infos_t *game)
{
    game->attack_position = get_next_line(0);
    convert_digit_into_x_y(game);
    return (0);
}