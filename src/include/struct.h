/*
** EPITECH PROJECT, 2020
** structures file
** File description:
** structures file
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <unistd.h>
#include <sys/types.h>

typedef struct base_infos_s
{
    int version;
    char **map;
    int manage_loop;
    char **enemys_map;
    int nrml;
    int state;
    char *attack_position;
    int enemy_x;
    int enemy_y;
    int counter_win;
    int counter_win_enemy;
    pid_t enemy_pid;

} base_infos_t;

struct DT
{
    int counter;
    int i;
    char *oldpwd;
    char *formated_string;
    char *temp;
    int a;
    int fill_string;
    int arg;
    int count_words;
    int ctrl_c;
    int return_value;
    char **tab;
};

#endif /* !STRUCT_H_ */
