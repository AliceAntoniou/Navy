/*
** EPITECH PROJECT, 2020
** navy
** File description:
** end game
*/

#include "../include/navy.h"

static int test_win(navy_t *main)
{
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (my_char_isnum(main->map_1[y][x]))
                return 0;
        }
    }
    return 1;
}

int end_game(int pid, navy_t *main, short player)
{
    if (player == 1) {
        if (receive_msg()) {
            my_putstr("I won\n\n");
            return 1;
        }
    }
    usleep(25);
    if (test_win(main)) {
        my_putstr ("Enemy won\n\n");
        send_msg(pid, 1);
        return 1;
    } else
        send_msg(pid, 0);
    if (player == 2) {
        if (receive_msg()) {
            my_putstr("I won\n\n");
            return 1;
        }
    }
    return 0;
}
