/*
** EPITECH PROJECT, 2020
** navy
** File description:
** init the game
*/

#include "../include/navy.h"

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(9);
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
        map[i][9] = '\0';
    }
    map[9] = NULL;
    return map;
}

void set_up_boats(const char *filename, navy_t *main)
{
    char pos[32];
    int fd = open(filename, O_RDONLY);
    int k = 0;
    int size = 0;

    read(fd, pos, 32);
    close(fd);
    pos[32] = '\0';
    for (int i = 0; i < 4; i++) {
        size = pos[k] - 48;
        for (int j = 0; j < size; j++) {
            if (pos[k + 2] == pos[k + 5])
                main->map_1[pos[k + 3] - 49 + j][pos[k + 2] - 65] = pos[k];
            if (pos[k + 3] == pos[k + 6])
                main->map_1[pos[k + 3] - 49][pos[k + 2] - 65 + j] = pos[k];
        }
        k += 8;
    }
}

int launch_game(int his_pid, const char *filename, short player)
{
    navy_t main;

    main.map_1 = create_map();
    main.map_2 = create_map();
    set_up_boats(filename, &main);
    return navy(his_pid, &main, player);
}