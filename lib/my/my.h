/*
** EPITECH PROJECT, 2020
** my fonctions
** File description:
** list of prototypes
*/

#ifndef MY_H
#define MY_H

#include <stddef.h>

void my_putchar(char c);
int my_strlen(char const *str);
int my_power(int nb, int p);
char *my_evil_str(char *str);
void my_putstr(char const *str);
void my_swap(char *a, char *b);
char *my_getstr(int nbr);
char *my_get_unsigned_str(unsigned int nbr);
void my_sort_int_array(int *array, int size);
int my_isneg(int n);
int my_getnbr(char const *str);
int my_getlen(int a);
int my_get_unsigned_len(unsigned int a);
int my_put_nbr(unsigned int nb);
int my_put_unsigned_nbr(unsigned int nb);
int my_char_isnum(char const c);
int my_char_isprintable(char const c);
void my_wait(int time);
char *convert_base(char const *, char const *, char const *);
char *my_strcpy(char *dest, char const *src);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *dec_to_uphex(char const *nbr);
char *dec_to_lowhex(char const *nbr);
char *dec_to_oct(char const *nbr);
char *dec_to_bin(char const *nbr);
int count_x(char *);
int count_y(char *);
void my_printf(char *fmt, ...);
int my_showstr(char const *str);
int give_nbr(char const *str, int loc, int side);
int get_nbr_len(int a);
char *my_strcat(char *dest , char  const *src);
int my_is_in_str(const char c, const char *str);

#endif