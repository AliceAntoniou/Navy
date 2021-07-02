/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game fonction
*/

#include "../include/navy.h"

void print_map(char **map)
{
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_putchar(map[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

void attack(int pid, navy_t *main)
{
    char *buf = malloc(sizeof(char) * 3);
    int x = 0;
    int y = 0;

    my_putstr("attack: ");
    read(0, buf, 3);
    x = buf[0] - 65;
    y = buf[1] - 49;
    send_msg(pid, my_getnbr(dec_to_bin(my_getstr(x))));
    send_msg(pid, my_getnbr(dec_to_bin(my_getstr(y))));
    buf[2] = '\0';
    my_printf("%s: ", buf);
    if (receive_msg()) {
        my_putstr("hit\n\n");
        main->map_2[y][x] = 'x';
    } else {
        my_putstr("missed\n\n");
        main->map_2[y][x] = 'o';
    }
}

void deffend(int pid, navy_t *main)
{
    int x;
    int y;

    my_putstr("waiting for enemy's attack...\n");
    x = receive_msg();
    y = receive_msg();
    my_printf("%c%c: ", x + 65, y + 49);
    if (main->map_1[y][x] != '.') {
        my_putstr("hit\n\n");
        main->map_1[y][x] = 'x';
        send_msg(pid, 1);
    } else {
        my_putstr("missed\n\n");
        main->map_1[y][x] = 'o';
        send_msg(pid, 0);
    }
}

int navy(int enemy_pid, navy_t *main, short player)
{
    while (1) {
        my_putstr("my positions:\n");
        print_map(main->map_1);
        my_putstr("enemy’s positions:\n");
        print_map(main->map_2);
        if (end_game(enemy_pid, main, player))
            return 0;
        if (player == 1) {
            attack(enemy_pid, main);
            deffend(enemy_pid, main);
        }
        if (player == 2) {
            deffend(enemy_pid, main);
            attack(enemy_pid, main);
        }
    }
    return 0;
}