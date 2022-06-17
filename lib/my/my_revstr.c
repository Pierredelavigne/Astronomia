/*
** EPITECH PROJECT, 2020
** new revstr
** File description:
** This is a better my_revstr
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    int count = 0;
    char *new_str = malloc(sizeof(char) * length + 1);

    for (count = 0; length - 1 >= 0; length--, count++) {
        new_str[count] = str[length-1];
    }
    new_str[count] = '\0';
    return (new_str);
}
