/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/struct.h"

int check_my_pid(char *pid)
{
    int len = my_strlen(pid);
    int i = 0;

    for (i = 0; pid[i] != 0 && pid[i] > 47 && pid[i] < 58; ++i);
    if (len != i)
        return (84);
    return (0);
}

int init_version(base_infos_t *game, char **av, int ac)
{
    int state = 0;

    if (ac == 2)
        game->version = HOST;
    else {
        game->version = CLIENT;
        state = check_my_pid(av[1]);
    }
    return (state);
}