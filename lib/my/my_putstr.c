/*
** EPITECH PROJECT, 2020
** my put str
** File description:
** print a string
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
