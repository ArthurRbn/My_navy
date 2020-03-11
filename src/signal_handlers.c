/*
** EPITECH PROJECT, 2020
** signal handlers
** File description:
** signal handlers
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/my.h"
#include "include/struct.h"

void sighandler(int signum, siginfo_t *sig, void *context)
{
    if (signum == SIGUSR1)
        bytes = 1;
    else if (signum == SIGUSR2)
        bytes = 2;
    (void)sig;
    (void)context;
}

int receiver(base_infos_t *info)
{
    struct sigaction act = {0};

    act.sa_sigaction = sighandler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    info->enemy_x = -3;
    info->enemy_y = -3;
    bytes = 0;
    while (bytes != 2) {
        pause();
        info->enemy_x += bytes;
    }
    bytes = 0;
    while (bytes != 2) {
        pause();
        info->enemy_y += bytes;
    }
    pause();
    return (bytes - 1);
}

void sig_init_handler(int signum, siginfo_t *sig, void *context)
{
    if (signum == SIGUSR1) {
        ++bytes;
    } if (signum == SIGUSR1 && bytes == 3) {
        bytes = sig->si_pid;
    }
    (void)context;
}

int hello_receiver(base_infos_t *info)
{
    struct sigaction act = {0};

    act.sa_sigaction = sig_init_handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (bytes < 3) {
        pause();
    }
    info->enemy_pid = bytes;
    return (bytes);
}

void transmitter(base_infos_t *info, int attack_x, int attack_y, int touched)
{
    for (int i = 0; i <= attack_x; ++i) {
        kill(info->enemy_pid, SIGUSR1);
        usleep(15000);
    }
    kill(info->enemy_pid, SIGUSR2);
    usleep(15000);
    for (int i = 0; i <= attack_y; ++i) {
        kill(info->enemy_pid, SIGUSR1);
        usleep(15000);
    }
    kill(info->enemy_pid, SIGUSR2);
    usleep(15000);
    if (touched == 0)
        kill(info->enemy_pid, SIGUSR1);
    else if (touched == 1)
        kill(info->enemy_pid, SIGUSR2);
}