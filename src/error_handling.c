/*
** EPITECH PROJECT, 2020
** navy
** File description:
** test if errors
*/

#include "../include/navy.h"

int check_char(const char *content)
{
    int ind = 0;

    while (content[ind] != '\0') {
        if (content[ind] == ':' || content[ind] == '\n')
            ind++;
        if ((content[ind] >= '1' && content[ind] <= '8')
            || (content[ind] >= 'A' && content[ind] <= 'H'))
            ind++;
        else if (content[ind] != '\0')
            return 1;
    }
    return 0;
}

int is_errors(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buf = malloc(sizeof(char) * 33);

    if (fd == -1)
        return 1;
    read(fd, buf, 32);
    buf[33] = '\0';
    close(fd);
    if (check_char(buf))
        return 1;
    free(buf);
    return 0;
}
