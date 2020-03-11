/*
** EPITECH PROJECT, 2020
** turn by turn
** File description:
** handling gaming process
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void host_interraction(base_infos_t *game)
{
    int attack_x = 0;
    int attack_y = 0;
    int touched = 0;
    char *enemy_attack = NULL;

    usleep(15000);
    get_attack(game);
    attack_x = game->attack_position[0] - 64;
    attack_y = game->attack_position[1] - 48;
    transmitter(game, attack_x, attack_y, 0);
    touched = receiver(game);
    my_printf("%s: %s\n\n", game->attack_position, is_touched(touched));
    print_on_enemy(game, touched);
    if (game->counter_win == 14)
        return;
    my_printf("waiting for enemy's attack...\n");
    receiver(game);
    enemy_attack = convert_enemy_attack(game);
    touched = put_x_or_o(game);
    my_printf("%s: %s\n\n", enemy_attack, is_touched(touched));
    transmitter(game, 9, 9, touched);
}

void client_interraction(base_infos_t *game)
{
    int attack_x = 0;
    int attack_y = 0;
    int touched = 0;
    char *enemy_attack = NULL;

    my_printf("waiting for enemy's attack...\n");
    receiver(game);
    enemy_attack = convert_enemy_attack(game);
    touched = put_x_or_o(game);
    my_printf("%s: %s\n\n", enemy_attack, is_touched(touched));
    transmitter(game, 9, 9, touched);
    if (game->counter_win_enemy == 14)
        return;
    usleep(15000);
    get_attack(game);
    attack_x = game->attack_position[0] - 64;
    attack_y = game->attack_position[1] - 48;
    transmitter(game, attack_x, attack_y, 0);
    touched = receiver(game);
    my_printf("%s: %s\n\n", game->attack_position, is_touched(touched));
    print_on_enemy(game, touched);
}

void last_print(base_infos_t *game)
{
    print_map_with_boat(game);
    my_printf("\n");
    print_map_enemy(game);
    if (game->counter_win == 14)
        my_printf("\nI won\n\n");
    else if (game->counter_win_enemy == 14)
        my_printf("\nEnemy won\n\n");
}