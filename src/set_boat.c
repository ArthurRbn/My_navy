/*
** EPITECH PROJECT, 2020
** boat
** File description:
** boat
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int count_y(base_infos_t *game, char **tab, int index_1, int index_2)
{
    int counter = 2;

    for (int a = 2; a < 10; ++a) {
        if (game->map[a][0] == tab[index_1][index_2])
            break;
        ++counter;
    }
    return (counter);

}

int count_x(base_infos_t *game, char **tab, int index_1, int index_2)
{
    int counter = 2;

    for (int i = 2; game->map[0][i]; ++i) {
        if (game->map[0][i] == tab[index_1][index_2])
            break;
        ++counter;
    }
    return (counter);
}

void fill_interval_y(base_infos_t *game, char **tab, int counter_x,
int counter_y)
{
    for (int i = my_getnbr(tab[0]) / 2; i > 0; --i) {
        game->map[counter_y - 1][counter_x] = tab[0][0];
        --counter_y;
    }
}

void fill_interval_x(base_infos_t *game, char **tab, int counter_x,
int counter_y)
{
    for (int i = my_getnbr(tab[0]) / 2; i >= 0; --i) {
        game->map[counter_y][counter_x - 2] = tab[0][0];
        counter_x -= 2;
    }
}

void set_boat(base_infos_t *game, char *path)
{
    int fd = open(path, O_RDONLY);
    char *boat;
    game->manage_loop = 0;
    char **positions;

    for (int i = 0; i < 4; ++i) {
        boat = get_next_line(fd);
        positions = my_path_to_word_array(boat);
        fill_boat(game, positions);
        game->manage_loop++;
    }
}