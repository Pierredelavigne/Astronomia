/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Alocates memory and copies the string given in it
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char  const *src)
{
    int lenght = my_strlen(src);
    char *new_str;
    int i = 0;

    new_str = malloc(sizeof(char) * (lenght + 1));
    while (src[i] != '\0') {
        new_str[i] = src[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
