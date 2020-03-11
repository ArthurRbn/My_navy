/*
** EPITECH PROJECT, 2020
** handle input
** File description:
** handler user input
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

enum letters{
    A = 2,
    B = 4,
    C = 6,
    D = 8,
    E = 10,
    F = 12,
    G = 14,
    H = 16,
};

int check_input(char *temp)
{
    if (!temp)
        return (84);
    if ((temp[0] > 64 && temp[0] < 73) && (temp[1] > 47 && temp[1] < 57))
        return (0);
    return (84);
}

int get_attack(base_infos_t *game)
{
    int a = 0;
    size_t retour = 0;
    char *temp = NULL;

    while (1) {
        my_printf("attack: ");
        a = getline(&temp, &retour, stdin);
        if (a == -1)
            return (84);
        if (check_input(temp) == 0 && a == 3) {
            game->attack_position = temp;
            game->attack_position[2] = 0;
            return (0);
        }
        my_printf("wrong position\n");
    }
    return (0);
}

char *is_touched(int state)
{
    if (state == 0)
        return ("missed");
    if (state == 1)
        return ("hit");
    return (NULL);
}

char *convert_enemy_attack(base_infos_t *game)
{
    char *enemy_attack = malloc(sizeof(char) * 3);

    enemy_attack[0] = game->enemy_x + 64;
    enemy_attack[1] = game->enemy_y + 48;
    enemy_attack[2] = 0;
    return (enemy_attack);
}