/*
** EPITECH PROJECT, 2020
** convert_dec_to_any_base_str.c
** File description:
** Convert any int in dec to any base
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

char *my_revstr(char *str);

char *convert_dec_to_any_base_str(int i, int base)
{
    char *to_base = malloc(sizeof(char) * i);
    int count = 0;

    for (;i > 0; count++) {
        to_base[count] = (i % base) + 48;
        i = i / base;
    }
    to_base[count] = '\0';
    return (my_revstr(to_base));
}
