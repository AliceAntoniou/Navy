/*
** EPITECH PROJECT, 2020
** navy
** File description:
** includes structures and macros
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

typedef struct navy
{
    char **map_1;
    char **map_2;
    int win;
} navy_t;

int set_up_connection(int pid, const char *filename);
int launch_game(int his_pid, const char *filename, short player);
void print_map(char **map);
int navy(int his_pid, navy_t *main, short player);
void send_msg(int pid, int nb);
int receive_msg();
int end_game(int pid, navy_t *main, short player);
int is_errors(const char *filename);

#endif /* !NAVY_H_ */
