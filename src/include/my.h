/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "struct.h"

#define HOST 0
#define CLIENT 1

int bytes;

//navy.c
void start_game(base_infos_t *game, char **av);
int win_check(base_infos_t *game);
int game_loop(base_infos_t *game);

//start_communication.c
void hello_sender(pid_t enemy_pid);
int host(base_infos_t *infos);
int confirm_connection(base_infos_t *infos);
base_infos_t *start_communication(int ac, char **av);

//signal_handlers.c
void sighandler(int signum, siginfo_t *sig, void *context);
int receiver(base_infos_t *info);
void sig_init_handler(int signum, siginfo_t *sig, void *context);
int hello_receiver(base_infos_t *infos);
void transmitter(base_infos_t *info, int attack_x, int attack_y, int touched);

//handle_input.c
int check_input(char *temp);
int get_attack(base_infos_t *game);
char *is_touched(int state);
char *convert_enemy_attack(base_infos_t *game);

//create_map.c
void print_map_with_boat(base_infos_t *game);
void print_map_enemy(base_infos_t *game);
int is_odd(int nbr);
void malloc_map_enemy(base_infos_t *game);
void malloc_map(base_infos_t *game);

//fill_maps.c
void fill_map_enemy(base_infos_t *game);
void fill_map_2_enemy(base_infos_t *game);
void fill_map_2(base_infos_t *game);
void last_fill_enemy(base_infos_t *game);
void fill_map(base_infos_t *game);

//map_handling.c
int error_for_x(char **tab);
int error_for_y(char **tab);
void create_map_enemy(base_infos_t *game);
void last_fill(base_infos_t *game);
void fill_boat(base_infos_t *game, char **tab);

//error_handling.c
int error_handling_nbr(char **tab, base_infos_t *game);
int error_handling_length(char **tab);
int check_letter(char *file);
int diagonal(char **tab);
int g_error(char **file, base_infos_t *game, int ac);

//error_handling_2.c
int check_my_pid(char *pid);
int init_version(base_infos_t *game, char **av, int ac);

//set_boat.c
int count_y(base_infos_t *game, char **tab, int index_1, int index_2);
int count_x(base_infos_t *game, char **tab, int index_1, int index_2);
void fill_interval_y(base_infos_t *game, char **tab, int counter_x,
int counter_y);
void fill_interval_x(base_infos_t *game, char **tab, int counter_x,
int counter_y);
void set_boat(base_infos_t *game, char *path);

//manage_shot.c
int put_x_or_o(base_infos_t *game);
void print_on_enemy(base_infos_t *game, int touched);

//turn_by_turn.c
void host_interraction(base_infos_t *game);
void client_interraction(base_infos_t *game);
void last_print(base_infos_t *game);

//utils
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
char **my_path_to_word_array(char *str);
int my_getnbr(char *src);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *get_next_line(int fd);

#endif //MY_H
