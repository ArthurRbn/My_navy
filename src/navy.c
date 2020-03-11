/*
** EPITECH PROJECT, 2020
** navy project
** File description:
** main file for the navy project
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

void start_game(base_infos_t *game, char **av)
{
    malloc_map(game);
    fill_map(game);
    if (game->version == HOST)
        set_boat(game, av[1]);
    else if (game->version == CLIENT)
        set_boat(game, av[2]);
    create_map_enemy(game);
    my_putstr("\n");
}

int win_check(base_infos_t *game)
{
    if (game->counter_win == 14)
        return (0);
    else if (game->counter_win_enemy == 14)
        return (1);
    else
        return (2);
}

int game_loop(base_infos_t *game)
{
    int win_state = 2;

    game->counter_win = 0;
    game->counter_win_enemy = 0;
    while (win_state == 2) {
        print_map_with_boat(game);
        my_printf("\n");
        print_map_enemy(game);
        my_printf("\n");
        if (game->version == HOST)
            host_interraction(game);
        else if (game->version == CLIENT)
            client_interraction(game);
        win_state = win_check(game);
    }
    last_print(game);
    return (win_state);
}

void information_of_the_game(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_poistions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. pid of the first");
    my_putstr(" player.\n  \tnavy_positions: file representing the positions");
    my_putstr(" of the ships.\n");
}

int main(int ac, char **av)
{
    base_infos_t *game = malloc(sizeof(base_infos_t));
    int ret_value = 0;
    bytes = 0;

    if (ac < 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
        information_of_the_game();
        return (0);
    }
    if (g_error(av, game, ac) == 84) {
        return (84);
    }
    game = start_communication(ac, av);
    start_game(game, av);
    ret_value = game_loop(game);
    return (ret_value);
}