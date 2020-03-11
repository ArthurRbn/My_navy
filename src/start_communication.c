/*
** EPITECH PROJECT, 2020
** functions to init communication
** File description:
** functions to init communication
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/my.h"
#include "include/struct.h"

void hello_sender(__pid_t enemy_pid)
{
    kill(enemy_pid, SIGUSR1);
    usleep(20000);
    kill(enemy_pid, SIGUSR1);
    usleep(20000);
    kill(enemy_pid, SIGUSR1);
}

int host(base_infos_t *infos)
{
    pid_t pid = getpid();
    int connect = 0;
    sigset_t mask;

    my_printf("my_pid: %d\nwaiting for enemy connection...\n", pid);
    sigemptyset(&mask);
    connect = hello_receiver(infos);
    my_printf("\nenemy connected\n");
    return (connect);
}

int confirm_connection(base_infos_t *infos)
{
    pid_t pid = getpid();
    int connect = 0;
    sigset_t mask;
    struct sigaction act = {0};

    act.sa_sigaction = sig_init_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    my_printf("my_pid: %d\n", pid);
    connect = hello_receiver(infos);
    my_printf("successfully connected\n");
    return (connect);
}

base_infos_t *start_communication(int ac, char **av)
{
    base_infos_t *info = malloc(sizeof(base_infos_t));

    if (ac <= 2) {
        host(info);
        hello_sender(info->enemy_pid);
        info->version = HOST;
    }
    else if (ac > 2) {
        hello_sender(my_getnbr(av[1]));
        confirm_connection(info);
        info->version = CLIENT;
    }
    return (info);
}