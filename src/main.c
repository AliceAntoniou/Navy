/*
** EPITECH PROJECT, 2020
** navi
** File description:
** main fonctions
*/

#include "../include/navy.h"

int print_usage(int argc, char const *argv[])
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("\t./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tfirst_player_pid: only for the 2nd player. ");
        my_putstr("pid of the first player.\n");
        my_putstr(
        "\tnavy_positions: file representing the positions of the ships.\n");
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (print_usage(argc, argv))
        return 0;
    if (argc == 2) {
        if (is_errors(argv[1]))
            return 84;
        return (set_up_connection(getpid(), argv[1]));
    }
    if (argc == 3) {
        if (is_errors(argv[2]))
            return 84;
        return (set_up_connection(my_getnbr(argv[1]), argv[2]));
    }
    return 84;
}