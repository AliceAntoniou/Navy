/*
** EPITECH PROJECT, 2020
** navy
** File description:
** data transfer fonctions
*/

#include "../include/navy.h"
#include "../include/global_var.h"

void send_msg(int pid, int nb)
{
    for (int i = 0; i < 3; i++) {
        usleep(25);
        if (nb % 10 == 0)
            kill(pid, SIGUSR1);
        if (nb % 10 == 1)
            kill(pid, SIGUSR2);
        nb /= 10;
    }
}

static void handler(int signum, siginfo_t *info, void *context)
{
    if (info->si_signo == SIGUSR1)
        global.bin = 0;
    if (info->si_signo == SIGUSR2)
        global.bin = 1;
}

int bin_to_dec(int binary_value)
{
    int decimal_value = 0;
    int base = 1;
    int rest;

    while (binary_value > 0) {
        rest = binary_value % 10;
        decimal_value = decimal_value + rest * base;
        binary_value = binary_value / 10;
        base = base * 2;
    }
    return (decimal_value);
}

int receive_msg(void)
{
    struct sigaction *action = malloc(sizeof(struct sigaction));
    sigset_t mask;
    int buff = 0;

    sigemptyset(&mask);
    action->sa_sigaction = handler;
    action->sa_flags = SA_SIGINFO;
    action->sa_mask = mask;
    for (int i = 0; i < 3; i++) {
        sigaction(SIGUSR1, action, NULL);
        sigaction(SIGUSR2, action, NULL);
    }
    free(action);
    for (int i = 0; i < 3; i++) {
        pause();
        buff += global.bin * my_power(10, i);
    }
    return (bin_to_dec(buff));
}