/*
** EPITECH PROJECT, 2020
** navy
** File description:
** set connection between terminals
*/

#include "../include/navy.h"
#include "../include/global_var.h"

struct global_struct global;

static void second_player_signal(void)
{
    global.pid_2 = getpid();
}

static void first_player_signal(int signum, siginfo_t *info, void *context)
{
    global.pid_2 = info->si_pid;
}

void first_player(const char *filename)
{
    struct sigaction *action = malloc(sizeof(struct sigaction));

    action->sa_sigaction = first_player_signal;
    action->sa_flags = SA_SIGINFO;
    sigemptyset(&action->sa_mask);
    my_putstr("waiting for enemy connection...\n");
    sigaction(SIGUSR1, action, NULL);
    while (global.pid_2 == 0)
        pause;
    my_putstr("\nenemy connected\n\n");
    kill(global.pid_2, SIGUSR1);
    launch_game(global.pid_2, filename, 1);
}

void second_player(const char *filename)
{
    kill(global.pid_1, SIGUSR1);
    signal(SIGUSR1, &second_player_signal);
    while (global.pid_2 == 0)
        pause;
    my_putstr("\nsuccessfully connected\n\n");
    launch_game(global.pid_1, filename, 2);
}

int set_up_connection(int pid, const char *filename)
{
    int my_pid = getpid();

    global.pid_1 = pid;
    global.pid_2 = 0;
    my_printf("my_pid: %d\n", my_pid);
    if (my_pid == pid) {
        first_player(filename);
    } else {
        second_player(filename);
    }
    return 0;
}
